#include "AlConfig.h"

#include <allegro5/allegro.h>
#include <cstring>

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

void AlConfig::setConfigValue(std::string section_name,std::string key,const char* value)
{
    al_set_config_value(config,section_name.c_str(),key.c_str(),value);
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
    if(tmp==NULL)
        return "";
    std::string s_tmp = tmp;
    return s_tmp;
}

std::vector<std::string> AlConfig::getConfigValueRows(std::string section_name,std::string key,int n)
{
    std::vector<std::string> vec;
    for(int i=1;i<=n;i++)
    {
        std::string tmp_key = key + std::to_string(i);
        std::string tmp = getConfigValue(section_name,tmp_key);
        vec.push_back(tmp);
    }
    return vec;
}
std::vector<std::string> AlConfig::getConfigValueRows(std::string section_name)
{
    ALLEGRO_CONFIG_ENTRY *entry;
    std::vector<std::string> vec;
    const char* tmp = al_get_first_config_entry(config,section_name.c_str(),&entry);
    if(tmp==NULL)
        {
            vec.push_back("");
            return vec;
        }
    std::string s_tmp ="";
    while (entry)
    {
        s_tmp=tmp;
        vec.push_back(s_tmp);
        tmp = al_get_next_config_entry(&entry);
    }
    return vec;
}

bool AlConfig::isFirstCreation()
{
    return creation;
}