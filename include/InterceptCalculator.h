#ifndef INTERCEPTCALCULATOR_H
#define INTERCEPTCALCULATOR_H

#include "Target.h"

class InterceptCalculator
{
public:
    void predictPosition(const Target& target, double secondsAhead) const;
};

#endif