#pragma once

#include <iostream>
#include <vector>
#include "../AlClasses/AlConfig.h"

class ScenesConfig
{
private:
    AlConfig config = AlConfig("scenes");
public:
    ScenesConfig();
    ~ScenesConfig();

    int getTileSize();
    int getHpBarX();
    int getHpBarY();
    int getPlayerX(std::string scene_name);
    int getPlayerY(std::string scene_name);
    std::vector<int> getTiles(std::string scene_name);
    std::string getEventPoints(std::string scene_name);
    std::string getEnemies(std::string scene_name);
};