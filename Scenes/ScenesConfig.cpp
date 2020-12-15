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
    std::vector<std::string> str_vec = config.getConfigValueRows("tiles_"+scene_name);
    std::string segment="";
    std::vector<int> vec;
    std::string value="";

    for(size_t i=0;str_vec.size()>i;i++)
    {
        value=str_vec[i];
        std::cout<<"val:"<<value<<std::endl;
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