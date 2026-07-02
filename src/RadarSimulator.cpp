#include "../include/RadarSimulator.h"

#include <cstdlib>
#include <ctime>

RadarSimulator::RadarSimulator()
{
    srand(static_cast<unsigned>(time(nullptr)));
}

void RadarSimulator::generateTargets(int count)
{
    for (int i = 0; i < count; i++)
    {
        Target target(
            i + 1,
            rand() % 1000,
            rand() % 1000,
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
}

std::vector<Target>& RadarSimulator::getTargets()
{
    return targets;
}