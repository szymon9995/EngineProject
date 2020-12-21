#include "BossScene.h"

void BossScene::OnCreate()
{
    std::string scene_name = "boss";
    SetPlayer(scene_name);
    SetUI(scene_name);
    CreateTiles(scene_name);
    SetEnemies(scene_name);

    camera.setCameraScreenSize(800,600);
    camera.setCameraToPlayer(&player);
    
}

void BossScene::GoNextScene()
{
    //manager->LoadScene(1);
}