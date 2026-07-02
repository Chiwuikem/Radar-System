#include "../include/InterceptCalculator.h"
#include <iostream>
#include <cmath>

void InterceptCalculator::predictPosition(const Target& target, double secondsAhead) const
{
    double radians = target.getHeading() * M_PI / 180.0;

    double futureX = target.getX() + target.getSpeed() * cos(radians) * secondsAhead;
    double futureY = target.getY() + target.getSpeed() * sin(radians) * secondsAhead;

    std::cout
        << " Predicted Position in "
        << secondsAhead
        << "s: ("
        << futureX
        << ", "
        << futureY
        << ")";
}