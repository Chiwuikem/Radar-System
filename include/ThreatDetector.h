#ifndef THREATDETECTOR_H
#define THREATDETECTOR_H

#include "Target.h"
#include <string>

class ThreatDetector
{
public:
    double calculateDistanceFromBase(const Target& target) const;
    bool isHeadingTowardBase(const Target& target) const;
    double calculateThreatScore(const Target& target) const;
    std::string classifyThreat(const Target& target) const;
};

#endif