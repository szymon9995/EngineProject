#include "SecondScene.h"

SecondScene::~SecondScene()
{
    
}

void SecondScene::OnCreate()
{
    std::string scene_name = "second";
    SetPlayer(scene_name);
    SetUI(scene_name);
    CreateTiles(scene_name);
    SetEnemies(scene_name);

    camera.setCameraScreenSize(800,600);
    camera.setCameraToPlayer(&player);
    
}

void SecondScene::GoNextScene()
{
    manager->LoadScene(2);
}