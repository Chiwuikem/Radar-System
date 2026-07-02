#ifndef RADARSIMULATOR_H
#define RADARSIMULATOR_H

#include "Target.h"
#include <vector>

class RadarSimulator
{
private:
    std::vector<Target> targets;
    double radarRange;
    int nextTargetId;

public:
    RadarSimulator();

    void generateTargets(int count);
    void performSweep(double seconds);

    void removeOutOfRangeTargets();
    void simulateSignalLoss();
    void detectNewTargets();
    void setRadarRange(double range);

    std::vector<Target>& getTargets();
};

#endif