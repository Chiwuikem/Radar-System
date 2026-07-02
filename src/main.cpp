#include "../include/RadarSimulator.h"
#include "../include/TrackManager.h"
#include "../include/ThreatDetector.h"
#include "../include/InterceptCalculator.h"
#include "../include/DisplayManager.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex radarMutex;

void radarThread(RadarSimulator& radar, TrackManager& tracker)
{
    for (int sweep = 1; sweep <= 10; sweep++)
    {
        std::lock_guard<std::mutex> lock(radarMutex);

        radar.performSweep(1);
        tracker.updateTracks(radar.getTargets());

        std::cout << "\nRadar sweep completed: " << sweep << "\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void analysisThread(
    TrackManager& tracker,
    ThreatDetector& detector,
    InterceptCalculator& intercept,
    DisplayManager& display
)
{
    for (int i = 1; i <= 10; i++)
    {
        std::lock_guard<std::mutex> lock(radarMutex);

        std::cout << "\n========== Threat Analysis " << i << " ==========\n";

        for (const auto& pair : tracker.getActiveTracks())
        {
            const Target& target = pair.second;
            std::string threatLevel = detector.classifyThreat(target);

            display.displayTarget(target, threatLevel);
            intercept.predictPosition(target, 5);

            std::cout << "\n";
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    RadarSimulator radar;
    TrackManager tracker;
    ThreatDetector detector;
    InterceptCalculator intercept;
    DisplayManager display;

    radar.generateTargets(5);
    tracker.updateTracks(radar.getTargets());

    std::thread t1(radarThread, std::ref(radar), std::ref(tracker));
    std::thread t2(
        analysisThread,
        std::ref(tracker),
        std::ref(detector),
        std::ref(intercept),
        std::ref(display)
    );

    t1.join();
    t2.join();

    return 0;
}