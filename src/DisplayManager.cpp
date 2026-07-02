#include "../include/DisplayManager.h"

#include <iostream>

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