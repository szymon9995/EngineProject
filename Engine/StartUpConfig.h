#pragma once
#include "../AlClasses/AlConfig.h"

class StartUpConfig
{
private:
    AlConfig startup = AlConfig("startup");

    //Display
    int display_w;
    int display_h;

    void LoadDisplayWidth();
    void LoadDisplayHeight();

public:
    StartUpConfig();
    ~StartUpConfig();
    //CreateDefult
    void createDeaultSettings();

    //Display config
    void setDefaultDisplayWidth();
    void setDisplayWidth(int w);
    void setDefaultDisplayHeight();
    void setDisplayHeight(int h);
    void setDefultDisplaySize();
    void setDisplaySize(int w,int h);

    int getDisplayWidth();
    int getDisplayHeight();


};

//Counstructocs/Deconstrucors
StartUpConfig::StartUpConfig()
{
    if(startup.isFirstCreation())
    {
        createDeaultSettings();
    }
    else
    {
        LoadDisplayWidth();
        LoadDisplayHeight();
    }
}

StartUpConfig::~StartUpConfig()
{

}

//Private
//Display
void StartUpConfig::LoadDisplayWidth()
{
    std::string tmp = startup.getConfigValue("display","w");
    if(tmp.empty())
    {
        setDefaultDisplayWidth();
    }
    else
    {
        display_w=std::stoi(tmp);
    }

}

void StartUpConfig::LoadDisplayHeight()
{
    std::string tmp = startup.getConfigValue("display","h");
    if(tmp.empty())
    {
        setDefaultDisplayHeight();
    }
    else
    {
        display_h=std::stoi(tmp);
    }
}

//Public
//Default

void StartUpConfig::createDeaultSettings()
{
    setDefultDisplaySize();
}

//Display
void StartUpConfig::setDefaultDisplayWidth()
{
    display_w = 800;
    startup.setConfigValue("display","w",display_w);
}

void StartUpConfig::setDisplayWidth(int w)
{
    display_w = w;
    startup.setConfigValue("display","w",w);
}

void StartUpConfig::setDefaultDisplayHeight()
{
    display_h = 600;
    startup.setConfigValue("display","h",display_h);
}

void StartUpConfig::setDisplayHeight(int h)
{
    display_h = h;
    startup.setConfigValue("display","h",h);
}

void StartUpConfig::setDefultDisplaySize()
{
    display_w = 800;
    display_h = 600;
    startup.setConfigValue("display","w",display_w);
    startup.setConfigValue("display","h",display_h);
}

void StartUpConfig::setDisplaySize(int w,int h)
{
    display_w = w;
    display_h = h;
    startup.setConfigValue("display","w",w);
    startup.setConfigValue("display","h",h);
}

int StartUpConfig::getDisplayWidth()
{
    return display_w;
}

int StartUpConfig::getDisplayHeight()
{
    return display_h;
}
