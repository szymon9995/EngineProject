#include "SceneManager.h"

#include "../Enitites/Tiles/Tile.h"
#include "../Scenes/SecondScene.h"
#include "../Scenes/BossScene.h"
#include "../Scenes/FirstScene.h"
#include "../Scenes/MenuScene.h"

SceneManager::SceneManager()
{
    cur_scene = NULL;
    isEnd=false;
}

SceneManager::~SceneManager()
{
    for(unsigned int i=0;i<sceneList.size();i++)
    {
        delete sceneList[i];
    }
    Tile::destroyTiles();

}

void SceneManager::Update()
{
    if(cur_scene!=NULL)
        cur_scene->Update();
}

void SceneManager::Draw()
{
    if(cur_scene!=NULL)
        cur_scene->Draw();
}

void SceneManager::UnloadScene()
{
    cur_scene=NULL;
}

void SceneManager::LoadScene(unsigned int sceneNum)
{
    UnloadScene();
    cur_scene = sceneList[sceneNum];
    cur_scene->OnLoad();
}

void SceneManager::AddScene(Scene *scene,unsigned int num)
{
    scene->OnCreate();
    sceneList[num] = scene;
}

void SceneManager::CreateFirst()
{
    AddScene(new MenuScene(this),0);
    AddScene(new FirstScene(this),1);
    AddScene(new SecondScene(this),2);
    AddScene(new BossScene(this),3);
    LoadScene(0);
    Tile::initTiles();
}

void SceneManager::stopApp()
{
    isEnd=true;
}

bool SceneManager::canEnd()
{
    return isEnd;
}
