#include "../include/InterceptCalculator.h"
#include <cmath>

InterceptCalculator::InterceptCalculator()
{
    interceptorSpeed = 35.0;
}

std::pair<double, double> InterceptCalculator::predictPosition(
    const Target& target,
    double secondsAhead
) const
{
    double radians = target.getHeading() * M_PI / 180.0;

    double futureX = target.getX() + target.getSpeed() * std::cos(radians) * secondsAhead;
    double futureY = target.getY() + target.getSpeed() * std::sin(radians) * secondsAhead;

    return {futureX, futureY};
}

double InterceptCalculator::calculateDistanceToIntercept(
    double futureX,
    double futureY
) const
{
    return std::sqrt(
        futureX * futureX +
        futureY * futureY
    );
}

bool InterceptCalculator::canIntercept(
    const Target& target,
    double secondsAhead
) const
{
    auto futurePosition = predictPosition(target, secondsAhead);

    double distanceToIntercept = calculateDistanceToIntercept(
        futurePosition.first,
        futurePosition.second
    );

    double timeNeeded = distanceToIntercept / interceptorSpeed;

    return timeNeeded <= secondsAhead;
}

double InterceptCalculator::calculateSuccessProbability(
    const Target& target,
    double secondsAhead
) const
{
    auto futurePosition = predictPosition(target, secondsAhead);

    double distanceToIntercept = calculateDistanceToIntercept(
        futurePosition.first,
        futurePosition.second
    );

    double timeNeeded = distanceToIntercept / interceptorSpeed;

    if (timeNeeded <= secondsAhead)
    {
        return 90.0;
    }
    else if (timeNeeded <= secondsAhead * 1.5)
    {
        return 60.0;
    }
    else if (timeNeeded <= secondsAhead * 2.0)
    {
        return 30.0;
    }

    return 10.0;
}

void InterceptCalculator::setInterceptorSpeed(double speed)
{
    interceptorSpeed = speed;
}