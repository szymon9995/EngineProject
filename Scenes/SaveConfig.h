#pragma once

#include"../Engine/StartUpConfig.h"

class SaveConfig
{
private:
    static AlConfig *config;
    static int scene;
    static int playerX;
    static int playerY;
    static bool load;
public:
    SaveConfig(/* args */);
    ~SaveConfig();


    static void initSave();
    static void endSave();
    static void saveProgress(int sceneLevel,int x,int y);
    static void loadProgress();
    static int getScene();
    static int getPlayerX();
    static int getPlayerY();
    static bool shouldLoad();

};
