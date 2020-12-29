#pragma once

#include "LevelSceneBase.h"

class SecondScene : public LevelSceneBase
{
private:
public:
    SecondScene(SceneManager* manager) : LevelSceneBase(manager){};
    ~SecondScene();
    void OnCreate();
    void GoNextScene();
    void SaveProgress();
};
