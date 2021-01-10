#include "SaveConfig.h"

AlConfig* SaveConfig::config = NULL;
int SaveConfig::playerX=0;
int SaveConfig::playerY=0;
int SaveConfig::scene=-1;
bool SaveConfig::load = false;

SaveConfig::SaveConfig()
{
}

SaveConfig::~SaveConfig()
{
}

int SaveConfig::getScene()
{
    return scene;
}

int SaveConfig::getPlayerX()
{
    return playerX;
}

int SaveConfig::getPlayerY()
{
    return playerY;
}

bool SaveConfig::shouldLoad()
{
    if(load==true)
    {
        load=false;
        return true;
    }
    return load;
}

void SaveConfig::saveProgress(int sceneLevel,int x,int y)
{
    scene = sceneLevel;
    playerX=x;
    playerY=y;
}

void SaveConfig::loadProgress()
{
    load=true;
}

void SaveConfig::initSave()
{
    if(config==NULL)
    {
        config = new AlConfig("savedata");
        scene=std::stoi(config->getConfigValue("save","scene"));
        playerX=std::stoi(config->getConfigValue("save","playerX"));
        playerY=std::stoi(config->getConfigValue("save","playerY"));
    }
}

void SaveConfig::endSave()
{
    if(config!=NULL)
    {
        config->setConfigValue("save","scene",scene);
        config->setConfigValue("save","playerX",playerX);
        config->setConfigValue("save","playerY",playerY);

        delete config;
        config = NULL;
    }
}