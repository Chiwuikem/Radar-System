#ifndef TRACKMANAGER_H
#define TRACKMANAGER_H

#include "Target.h"
#include <unordered_map>
#include <vector>

class TrackManager
{
private:
    std::unordered_map<int, Target> activeTracks;

public:
    void updateTracks(const std::vector<Target>& detectedTargets);

    const std::unordered_map<int, Target>& getActiveTracks() const;
};

#endif