#include "SceneManager.h"

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
    //sceneList.insert(num,scene);
}

void SceneManager::CreateFirst()
{
    testScene.OnCreate();
    cur_scene = &testScene;
    //cur_scene = sceneList[0];
}