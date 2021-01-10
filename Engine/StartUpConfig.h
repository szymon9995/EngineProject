#pragma once
#include "../AlClasses/AlConfig.h"

class StartUpConfig
{
private:
    AlConfig startup = AlConfig("startup");

    //Display
    static int display_w;
    static int display_h;
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

    static int getDisplayWidth();
    static int getDisplayHeight();
    bool getDisplayMode();
    bool getDisplayIsResizable();

};