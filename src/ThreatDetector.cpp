#include "../include/ThreatDetector.h"
#include <cmath>

double ThreatDetector::calculateDistanceFromBase(const Target& target) const
{
    return std::sqrt(
        target.getX() * target.getX() +
        target.getY() * target.getY()
    );
}

bool ThreatDetector::isHeadingTowardBase(const Target& target) const
{
    double radians = target.getHeading() * M_PI / 180.0;

    double velocityX = target.getSpeed() * std::cos(radians);
    double velocityY = target.getSpeed() * std::sin(radians);

    double dotProduct =
        (target.getX() * velocityX) +
        (target.getY() * velocityY);

    return dotProduct < 0;
}

double ThreatDetector::calculateThreatScore(const Target& target) const
{
    double distance = calculateDistanceFromBase(target);
    double score = 0;

    if (distance < 100)
        score += 50;
    else if (distance < 250)
        score += 35;
    else if (distance < 500)
        score += 20;
    else
        score += 5;

    if (target.getSpeed() > 20)
        score += 25;
    else if (target.getSpeed() > 12)
        score += 15;
    else
        score += 5;

    if (isHeadingTowardBase(target))
        score += 25;

    if (score > 100)
        score = 100;

    return score;
}

std::string ThreatDetector::classifyThreat(const Target& target) const
{
    double score = calculateThreatScore(target);

    if (score >= 85)
        return "CRITICAL";
    else if (score >= 65)
        return "HIGH";
    else if (score >= 40)
        return "MEDIUM";

    return "LOW";
}