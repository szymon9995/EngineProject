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
    int getTileMapRows(std::string scene_name);
    std::vector<int> getBats(std::string scene_name);
    std::vector<int> getZombies(std::string scene_name);
    int getExitX(std::string scene_name);
    int getExitY(std::string scene_name);
};