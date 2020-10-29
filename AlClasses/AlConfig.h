#pragma once
#include <allegro5/allegro.h>
#include <cstring>
#include <iostream>

class AlConfig
{
private:
    ALLEGRO_CONFIG *config;
    std::string name;
    bool creation;
public:
    AlConfig(std::string name);
    ~AlConfig();

    void addConfigSection(std::string section_name);

    void setConfigValue(std::string section_name,std::string key,std::string value);
    void setConfigValue(std::string section_name,std::string key,int value);
    void setConfigValue(std::string section_name,std::string key,long value);
    void setConfigValue(std::string section_name,std::string key,double value);
    void setConfigValue(std::string section_name,std::string key,bool value);

    std::string getConfigValue(std::string section_name,std::string key);

    bool isFirstCreation();
};

AlConfig::AlConfig(std::string name)
{
    name+=".cfg";
    
    config = al_load_config_file(name.c_str());
    if(config==NULL)
    {
        config = al_create_config();
        creation=true;
    }
    else
    {
        creation=false;
    }
    
    this->name=name;
}

AlConfig::~AlConfig()
{
    ///mabye save with a difrent method or a way
    al_save_config_file(name.c_str(),config);
    al_destroy_config(config);
}

void AlConfig::addConfigSection(std::string section_name)
{
    al_add_config_section(config,section_name.c_str());
}

void AlConfig::setConfigValue(std::string section_name,std::string key,std::string value)
{
    al_set_config_value(config,section_name.c_str(),key.c_str(),value.c_str());
}

void AlConfig::setConfigValue(std::string section_name,std::string key,int value)
{
    al_set_config_value(config,section_name.c_str(),key.c_str(),std::to_string(value).c_str());
}

void AlConfig::setConfigValue(std::string section_name,std::string key,long value)
{
    al_set_config_value(config,section_name.c_str(),key.c_str(),std::to_string(value).c_str());
}

void AlConfig::setConfigValue(std::string section_name,std::string key,double value)
{
    al_set_config_value(config,section_name.c_str(),key.c_str(),std::to_string(value).c_str());
}

void AlConfig::setConfigValue(std::string section_name,std::string key,bool value)
{
    al_set_config_value(config,section_name.c_str(),key.c_str(),std::to_string(value).c_str());
}

std::string AlConfig::getConfigValue(std::string section_name,std::string key)
{
    const char* tmp = al_get_config_value(config,section_name.c_str(),key.c_str());
    std::string s_tmp = tmp;
    return s_tmp;
}

bool AlConfig::isFirstCreation()
{
    return creation;
}