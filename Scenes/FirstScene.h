#pragma once

#include "LevelSceneBase.h"

class FirstScene : public LevelSceneBase
{
private:
    
public:
    FirstScene(SceneManager* manager) : LevelSceneBase(manager){};
    ~FirstScene();
    void OnCreate();
    void GoNextScene();
    void SaveProgress();
};
