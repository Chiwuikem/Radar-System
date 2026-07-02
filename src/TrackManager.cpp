#include "../include/TrackManager.h"

void TrackManager::updateTracks(const std::vector<Target>& detectedTargets)
{
    for (const auto& target : detectedTargets)
    {
        activeTracks.insert_or_assign(target.getId(), target);
    }
}

const std::unordered_map<int, Target>& TrackManager::getActiveTracks() const
{
    return activeTracks;
}