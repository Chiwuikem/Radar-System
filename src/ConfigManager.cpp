#include "../include/ConfigManager.h"
#include <fstream>
#include <sstream>

bool ConfigManager::loadConfig(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string key;
        std::string value;

        if (std::getline(ss, key, '=') && std::getline(ss, value))
        {
            settings[key] = std::stod(value);
        }
    }

    return true;
}

double ConfigManager::getValue(const std::string& key, double defaultValue) const
{
    auto it = settings.find(key);

    if (it != settings.end())
    {
        return it->second;
    }

    return defaultValue;
}