#pragma once

#include "LevelSceneBase.h"

class BossScene : public LevelSceneBase
{
private:
    
public:
    BossScene(SceneManager* manager) : LevelSceneBase(manager){};
    ~BossScene(){};
    void OnCreate();
    void GoNextScene();
    void SaveProgress();
};