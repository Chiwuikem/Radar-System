#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "Target.h"
#include <string>

class DisplayManager
{
public:
    void displayTarget(
        const Target& target,
        const std::string& threat
    ) const;
};

#endif