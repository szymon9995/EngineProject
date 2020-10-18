#pragma once
#include <allegro5/allegro.h>

class AlConfig
{
private:
    ALLEGRO_CONFIG *config;
    ALLEGRO_CONFIG_ENTRY *entry;
public:
    AlConfig();
    ~AlConfig();

    void CreateDefault();
    
    void SetDisplaySize(int w,int h);
};

AlConfig::AlConfig()
{
    config = al_load_config_file("startup.cfg");
    if(config==NULL)
    {
        CreateDefault();
    }
}

AlConfig::~AlConfig()
{
    ///////////
    free(entry);
    //////////
    al_destroy_config(config);
}

void AlConfig::CreateDefault()
{
    config = al_create_config();
    
    //test value
    al_add_config_section(config,"test");

    al_set_config_value(config,"test","foo","1");

    //display config
    

    //////////////////////

    al_save_config_file("startup.cfg",config);
}

void AlConfig::SetDisplaySize(int w,int h)
{
    al_add_config_section(config,"display");
    if(w<1)
        w=800;
    if(h<1)
        h=600;
    al_set_config_value(config,"display","w",""+w);
    al_set_config_value(config,"display","h",""+h);
}
