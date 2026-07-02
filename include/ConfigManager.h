#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <string>
#include <unordered_map>

class ConfigManager
{
private:
    std::unordered_map<std::string, double> settings;

public:
    bool loadConfig(const std::string& filename);
    double getValue(const std::string& key, double defaultValue) const;
};

#endif