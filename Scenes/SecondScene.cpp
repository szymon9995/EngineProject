#include "SecondScene.h"

SecondScene::~SecondScene()
{
    OnDestroy();
}

void SecondScene::OnCreate()
{
    scene_name = "second";
    SetPlayer(scene_name);
    SetUI(scene_name);
    CreateTiles(scene_name);
    SetEnemies(scene_name);

    camera.setCameraScreenSize(800,600);
    camera.setCameraToPlayer(&player);
    
}

void SecondScene::GoNextScene()
{
    manager->LoadScene(3);
}

void SecondScene::SaveProgress()
{
    AlConfig tmp = AlConfig("savedata");
    tmp.setConfigValue("save","scene",2);
    tmp.setConfigValue("save","playerX",sceneConfig.getPlayerX("second"));
    tmp.setConfigValue("save","playerY",sceneConfig.getPlayerY("second"));
}