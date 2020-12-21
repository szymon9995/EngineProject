#include "ScenesConfig.h"

ScenesConfig::ScenesConfig()
{
    
}

ScenesConfig::~ScenesConfig()
{
}

int ScenesConfig::getTileSize()
{
    std::string value = config.getConfigValue("universal","tilesize");
    int tilesize = std::stoi(value);
    return tilesize;
}

int ScenesConfig::getHpBarX()
{
    std::string value = config.getConfigValue("universal","HpBarX");
    int x = std::stoi(value);
    return x;
}

int ScenesConfig::getHpBarY()
{
    std::string value = config.getConfigValue("universal","HPBarY");
    int y = std::stoi(value);
    return y;
}

int ScenesConfig::getPlayerX(std::string scene_name)
{
    std::string value = config.getConfigValue(scene_name.c_str(),"PlayerX");
    int x = std::stoi(value);
    return x;
}

int ScenesConfig::getPlayerY(std::string scene_name)
{
    std::string value = config.getConfigValue(scene_name.c_str(),"PlayerY");
    int y = std::stoi(value);
    return y;
}

std::vector<int> ScenesConfig::getTiles(std::string scene_name)
{
    int tilesR = getTileMapRows(scene_name);
    std::vector<std::string> str_vec = config.getConfigValueRows("tiles_"+scene_name,"r",tilesR);
    std::string segment="";
    std::vector<int> vec;
    std::string value="";

    for(size_t i=0;str_vec.size()>i;i++)
    {
        value=str_vec[i];
        for(size_t j=0;value.length()+1>j;j++)
        {
        if(value[j]==' ' || value[j]=='\0')
        {
            vec.push_back(std::stoi(segment));
            segment="";
            continue;
        }
        
        segment+=value[j];
        }

        vec.push_back(-1);
    }
    return vec;
}

int ScenesConfig::getTileMapRows(std::string scene_name)
{
    std::string tmp = "tiles_"+scene_name;
    std::string value = config.getConfigValue(tmp.c_str(),"rows");
    int val = std::stoi(value);
    return val;
}

std::vector<int> ScenesConfig::getBats(std::string scene_name)
{
    std::string tmp = "bat_"+scene_name;
    int bats = std::stoi(config.getConfigValue(tmp.c_str(),"bats"));
    std::vector<std::string> str_vec= config.getConfigValueRows(tmp,"b",bats);

    std::string segment="";
    std::vector<int> vec;
    std::string value="";

    for(size_t i=0;str_vec.size()>i;i++)
    {
        
        value=str_vec[i];
        for(size_t j=0;value.length()+1>j;j++)
        {
        if(value[j]==' ' || value[j]=='\0')
        {
            vec.push_back(std::stoi(segment));
            segment="";
            continue;
        }
        
        segment+=value[j];
        }
    }
    return vec;
}

std::vector<int> ScenesConfig::getZombies(std::string scene_name)
{
    std::string tmp = "zombie_"+scene_name;
    int zombies = std::stoi(config.getConfigValue(tmp.c_str(),"zombies"));
    std::vector<std::string> str_vec= config.getConfigValueRows(tmp,"z",zombies);

    std::string segment="";
    std::vector<int> vec;
    std::string value="";

    for(size_t i=0;str_vec.size()>i;i++)
    {
        
        value=str_vec[i];
        for(size_t j=0;value.length()+1>j;j++)
        {
        if(value[j]==' ' || value[j]=='\0')
        {
            vec.push_back(std::stoi(segment));
            segment="";
            continue;
        }
        
        segment+=value[j];
        }
    }
    return vec;
}

int ScenesConfig::getExitX(std::string scene_name)
{
     std::string value = config.getConfigValue(scene_name.c_str(),"exitx");
    int x = std::stoi(value);
    return x;
}

int ScenesConfig::getExitY(std::string scene_name)
{
    std::string value = config.getConfigValue(scene_name.c_str(),"exity");
    int y = std::stoi(value);
    return y;
}