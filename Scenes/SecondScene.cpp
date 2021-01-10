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
    SetCamera();
}

void SecondScene::GoNextScene()
{
    manager->LoadScene(3);
}

void SecondScene::SaveProgress()
{

    SaveConfig::saveProgress(2,sceneConfig.getPlayerX("second"),sceneConfig.getPlayerY("second"));

    std::cout<<"Saving"<<std::endl;
    std::cout<<"Scene:"<<SaveConfig::getScene()<<std::endl;
    std::cout<<"PlayerX:"<<SaveConfig::getPlayerX()<<std::endl;
    std::cout<<"PlayerY:"<<SaveConfig::getPlayerY()<<std::endl;
}