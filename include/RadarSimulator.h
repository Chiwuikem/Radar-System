#ifndef RADARSIMULATOR_H
#define RADARSIMULATOR_H

#include "Target.h"
#include <vector>

class RadarSimulator
{
private:
    std::vector<Target> targets;

public:
    RadarSimulator();

    void generateTargets(int count);

    void performSweep(double seconds);

    std::vector<Target>& getTargets();
};

#endif