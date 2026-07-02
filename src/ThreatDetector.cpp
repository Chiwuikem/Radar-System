#include "../include/ThreatDetector.h"
#include <cmath>

std::string ThreatDetector::classifyThreat(const Target& target) const
{
    double distanceFromBase = std::sqrt(
        target.getX() * target.getX() +
        target.getY() * target.getY()
    );

    if (distanceFromBase < 100 && target.getSpeed() > 20)
    {
        return "CRITICAL";
    }
    else if (distanceFromBase < 250)
    {
        return "HIGH";
    }
    else if (distanceFromBase < 500)
    {
        return "MEDIUM";
    }

    return "LOW";
}