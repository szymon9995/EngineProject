#include "SceneManager.h"

#include "../Enitites/Tiles/Tile.h"
#include "../Scenes/SecondScene.h"
#include "../Scenes/BossScene.h"

SceneManager::SceneManager()
{
    cur_scene = NULL;
}

SceneManager::~SceneManager()
{
    for(unsigned int i=0;i<sceneList.size();i++)
    {
        delete sceneList[i];
    }

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
}

void SceneManager::AddScene(Scene *scene,unsigned int num)
{
    scene->OnCreate();
    sceneList[num] = scene;
}

void SceneManager::CreateFirst()
{
    AddScene(new TestScene(this),0);
    AddScene(new SecondScene(this),1);
    AddScene(new BossScene(this),2);
    cur_scene = sceneList[0];
    Tile::initTiles();
}
