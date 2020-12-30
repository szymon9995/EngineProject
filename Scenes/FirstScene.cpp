#include "FirstScene.h"

FirstScene::~FirstScene()
{
    OnDestroy();
}

void FirstScene::OnCreate()
{
    scene_name = "test";
    SetPlayer(scene_name);
    SetUI(scene_name);
    CreateTiles(scene_name);
    SetEnemies(scene_name);

    camera.setCameraScreenSize(800,600);
    camera.setCameraToPlayer(&player);
    
}

void FirstScene::GoNextScene()
{
    manager->LoadScene(2);
}

void FirstScene::SaveProgress()
{
    std::cout<<"Saving"<<std::endl;
    AlConfig tmp = AlConfig("savedata");
    tmp.setConfigValue("save","scene",1);
    tmp.setConfigValue("save","playerX",sceneConfig.getPlayerX("test"));
    tmp.setConfigValue("save","playerY",sceneConfig.getPlayerY("test"));
    tmp.manualSave();
    std::cout<<tmp.getConfigValue("save","scene");
    std::cout<<tmp.getConfigValue("save","playerX");
    std::cout<<tmp.getConfigValue("save","playerY");
}