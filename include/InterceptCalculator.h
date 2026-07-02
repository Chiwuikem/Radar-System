#ifndef INTERCEPTCALCULATOR_H
#define INTERCEPTCALCULATOR_H

#include "Target.h"
#include <utility>

class InterceptCalculator
{
private:
    double interceptorSpeed;

public:
    InterceptCalculator();
    void setInterceptorSpeed(double speed);
    
    std::pair<double, double> predictPosition(
        const Target& target,
        double secondsAhead
    ) const;

    double calculateDistanceToIntercept(
        double futureX,
        double futureY
    ) const;

    bool canIntercept(
        const Target& target,
        double secondsAhead
    ) const;

    double calculateSuccessProbability(
        const Target& target,
        double secondsAhead
    ) const;
};

#endif