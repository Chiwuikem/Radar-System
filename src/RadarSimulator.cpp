#include "../include/RadarSimulator.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

RadarSimulator::RadarSimulator()
{
    srand(static_cast<unsigned>(time(nullptr)));
    radarRange = 1000.0;
    nextTargetId = 1;
}

void RadarSimulator::generateTargets(int count)
{
    for (int i = 0; i < count; i++)
    {
        Target target(
            nextTargetId++,
            rand() % 800,
            rand() % 800,
            5 + rand() % 20,
            rand() % 360
        );

        targets.push_back(target);
    }
}

void RadarSimulator::performSweep(double seconds)
{
    for (auto& target : targets)
    {
        target.updatePosition(seconds);
    }

    removeOutOfRangeTargets();
    simulateSignalLoss();
    detectNewTargets();
}

void RadarSimulator::removeOutOfRangeTargets()
{
    targets.erase(
        std::remove_if(
            targets.begin(),
            targets.end(),
            [this](const Target& target)
            {
                double distance = std::sqrt(
                    target.getX() * target.getX() +
                    target.getY() * target.getY()
                );

                return distance > radarRange;
            }
        ),
        targets.end()
    );
}

void RadarSimulator::simulateSignalLoss()
{
    targets.erase(
        std::remove_if(
            targets.begin(),
            targets.end(),
            [](const Target& target)
            {
                return rand() % 100 < 10;
            }
        ),
        targets.end()
    );
}

void RadarSimulator::detectNewTargets()
{
    int chance = rand() % 100;

    if (chance < 30)
    {
        Target newTarget(
            nextTargetId++,
            rand() % 800,
            rand() % 800,
            5 + rand() % 20,
            rand() % 360
        );

        targets.push_back(newTarget);
    }
}

void RadarSimulator::setRadarRange(double range)
{
    radarRange = range;
}

std::vector<Target>& RadarSimulator::getTargets()
{
    return targets;
}