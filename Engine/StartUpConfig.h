#pragma once
#include "../AlClasses/AlConfig.h"

class StartUpConfig
{
private:
    AlConfig startup = AlConfig("startup");

    //Display
    int display_w;
    int display_h;
    bool display_isFull;
    bool display_isResizable;

    void LoadDisplayWidth();
    void LoadDisplayHeight();
    void LoadDiplayMode();
    void LoadDisplayIsResizable();

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

    void setDefaultDisplayMode();
    void setDisplayMode(bool isFullScreen);
    void setDefaultDiplayIsResizable();
    void setDiplayIsResizable(bool isResizable);

    int getDisplayWidth();
    int getDisplayHeight();
    bool getDisplayMode();
    bool getDisplayIsResizable();

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
        LoadDisplayIsResizable();
        LoadDiplayMode();
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

void StartUpConfig::LoadDiplayMode()
{
    std::string tmp = startup.getConfigValue("display","mode");
    if(tmp.empty())
        setDefaultDisplayMode();
    if(tmp=="true")
        display_isFull=true;
    else
        display_isFull=false;

}

void StartUpConfig::LoadDisplayIsResizable()
{
    std::string tmp = startup.getConfigValue("display","resizable");
    if(tmp.empty())
        setDefaultDiplayIsResizable();
    else if(tmp=="true")
        display_isResizable=true;
    else
        display_isResizable=false;
}

//Public
//Default

void StartUpConfig::createDeaultSettings()
{
    //Display
    setDefultDisplaySize();
    setDefaultDisplayMode();
    setDefaultDiplayIsResizable();
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

void StartUpConfig::setDefaultDisplayMode()
{
    display_isFull = false;
    startup.setConfigValue("display","mode","false");
}

void StartUpConfig::setDisplayMode(bool isFullScreen)
{
     if(isFullScreen==false)
        startup.setConfigValue("display","mode","false");
    else
        startup.setConfigValue("display","mode","true");
}

void StartUpConfig::setDefaultDiplayIsResizable()
{
    display_isResizable = false;
    startup.setConfigValue("display","resizable","false");
}
void StartUpConfig::setDiplayIsResizable(bool isResizable)
{
    if(isResizable==false)
        startup.setConfigValue("display","resizable","false");
    else
        startup.setConfigValue("display","resizable","true");
}

int StartUpConfig::getDisplayWidth()
{
    return display_w;
}

int StartUpConfig::getDisplayHeight()
{
    return display_h;
}

bool StartUpConfig::getDisplayMode()
{
    return display_isFull;
}

bool StartUpConfig::getDisplayIsResizable()
{
    return display_isResizable;
}
