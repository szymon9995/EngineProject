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
    SetCamera();
}

void FirstScene::GoNextScene()
{
    manager->LoadScene(2);
}

void FirstScene::SaveProgress()
{
    SaveConfig::saveProgress(1,sceneConfig.getPlayerX("test"),sceneConfig.getPlayerY("test"));
}