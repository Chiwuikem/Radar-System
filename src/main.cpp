#include "../include/RadarSimulator.h"
#include "../include/TrackManager.h"
#include "../include/ThreatDetector.h"
#include "../include/InterceptCalculator.h"
#include "../include/DisplayManager.h"
#include "../include/ConfigManager.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <utility>

std::mutex radarMutex;

void radarThread(
    RadarSimulator& radar,
    TrackManager& tracker,
    int sweepCount,
    int sweepDelay
)
{
    for (int sweep = 1; sweep <= sweepCount; sweep++)
    {
        {
            std::lock_guard<std::mutex> lock(radarMutex);

            radar.performSweep(1);
            tracker.updateTracks(radar.getTargets());

            std::cout << "\nRadar sweep completed: " << sweep << "\n";
        }

        std::this_thread::sleep_for(std::chrono::seconds(sweepDelay));
    }
}

void analysisThread(
    TrackManager& tracker,
    ThreatDetector& detector,
    InterceptCalculator& intercept,
    DisplayManager& display,
    int sweepCount,
    int sweepDelay
)
{
    for (int i = 1; i <= sweepCount; i++)
    {
        {
            std::lock_guard<std::mutex> lock(radarMutex);

            std::cout << "\n========== Threat Analysis " << i << " ==========\n";

            display.displayRadarMap(tracker.getActiveTracks());

            for (const auto& pair : tracker.getActiveTracks())
            {
                const Target& target = pair.second;

                std::string threatLevel = detector.classifyThreat(target);
                double threatScore = detector.calculateThreatScore(target);
                bool headingTowardBase = detector.isHeadingTowardBase(target);
                double distance = detector.calculateDistanceFromBase(target);

                auto futurePosition = intercept.predictPosition(target, 5);
                bool interceptPossible = intercept.canIntercept(target, 5);
                double successProbability =
                    intercept.calculateSuccessProbability(target, 5);

                display.displayTarget(target, threatLevel);

                std::cout
                    << "Distance        : " << distance << "\n"
                    << "Toward Base     : " << (headingTowardBase ? "YES" : "NO") << "\n"
                    << "Threat Score    : " << threatScore << "/100\n"
                    << "Future Position : ("
                    << futurePosition.first << ", "
                    << futurePosition.second << ")\n"
                    << "Interceptable   : "
                    << (interceptPossible ? "YES" : "NO") << "\n"
                    << "Success Chance  : "
                    << successProbability << "%\n";
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(sweepDelay));
    }
}

int main()
{
    RadarSimulator radar;
    TrackManager tracker;
    ThreatDetector detector;
    InterceptCalculator intercept;
    DisplayManager display;

    ConfigManager config;
    bool configLoaded = config.loadConfig("config.txt");

    if (!configLoaded)
    {
        std::cout << "Warning: config.txt not found. Using default settings.\n";
    }

    radar.setRadarRange(config.getValue("RadarRange", 1000));
    intercept.setInterceptorSpeed(config.getValue("InterceptorSpeed", 35));

    int sweepCount = static_cast<int>(config.getValue("SweepCount", 10));
    int sweepDelay = static_cast<int>(config.getValue("SweepDelaySeconds", 1));

    radar.generateTargets(5);
    tracker.updateTracks(radar.getTargets());

    std::thread t1(
        radarThread,
        std::ref(radar),
        std::ref(tracker),
        sweepCount,
        sweepDelay
    );

    std::thread t2(
        analysisThread,
        std::ref(tracker),
        std::ref(detector),
        std::ref(intercept),
        std::ref(display),
        sweepCount,
        sweepDelay
    );

    t1.join();
    t2.join();

    return 0;
}