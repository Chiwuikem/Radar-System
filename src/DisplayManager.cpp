#include "../include/DisplayManager.h"

#include <iostream>
#include <vector>
#include <cmath>

void DisplayManager::displayTarget(
    const Target& target,
    const std::string& threat
) const
{
    std::cout
        << "--------------------------------------\n"
        << "Target ID: " << target.getId() << "\n"
        << "Position : (" << target.getX()
        << ", " << target.getY() << ")\n"
        << "Speed    : " << target.getSpeed() << "\n"
        << "Heading  : " << target.getHeading() << " degrees\n"
        << "Threat   : " << threat << "\n";
}

void DisplayManager::displayRadarMap(
    const std::unordered_map<int, Target>& tracks
) const
{
    const int gridSize = 21;
    const int center = gridSize / 2;
    const double scale = 50.0;

    std::vector<std::vector<char>> grid(
        gridSize,
        std::vector<char>(gridSize, '.')
    );

    grid[center][center] = 'B';

    for (const auto& pair : tracks)
    {
        const Target& target = pair.second;

        int gridX = center + static_cast<int>(target.getX() / scale);
        int gridY = center - static_cast<int>(target.getY() / scale);

        if (
            gridX >= 0 &&
            gridX < gridSize &&
            gridY >= 0 &&
            gridY < gridSize
        )
        {
            grid[gridY][gridX] = '*';
        }
    }

    std::cout << "\n=========== RADAR MAP ===========\n";
    std::cout << "B = Base | * = Target\n\n";

    for (const auto& row : grid)
    {
        for (char cell : row)
        {
            std::cout << cell << ' ';
        }

        std::cout << '\n';
    }

    std::cout << "=================================\n";
}