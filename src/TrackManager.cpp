#include "../include/TrackManager.h"
#include <unordered_set>

void TrackManager::updateTracks(const std::vector<Target>& detectedTargets)
{
    for (const auto& target : detectedTargets)
    {
        activeTracks.insert_or_assign(target.getId(), target);
    }

    removeLostTracks(detectedTargets);
}

void TrackManager::removeLostTracks(const std::vector<Target>& detectedTargets)
{
    std::unordered_set<int> currentIds;

    for (const auto& target : detectedTargets)
    {
        currentIds.insert(target.getId());
    }

    for (auto it = activeTracks.begin(); it != activeTracks.end(); )
    {
        if (currentIds.find(it->first) == currentIds.end())
        {
            it = activeTracks.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

const std::unordered_map<int, Target>& TrackManager::getActiveTracks() const
{
    return activeTracks;
}