#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "Target.h"
#include <string>
#include <unordered_map>

class DisplayManager
{
public:
    void displayTarget(
        const Target& target,
        const std::string& threat
    ) const;

    void displayRadarMap(
        const std::unordered_map<int, Target>& tracks
    ) const;
};

#endif