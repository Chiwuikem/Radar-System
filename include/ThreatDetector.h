#ifndef THREATDETECTOR_H
#define THREATDETECTOR_H

#include "Target.h"
#include <string>

class ThreatDetector
{
public:
    std::string classifyThreat(const Target& target) const;
};

#endif