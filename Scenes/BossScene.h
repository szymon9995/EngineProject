#pragma once

#include "LevelSceneBase.h"
#include "../Enitites/Enemies/EnemyBoss.h"

class BossScene : public LevelSceneBase
{
private:
    EnemyBoss* boss;
    Tile* blockade[3];
public:
    BossScene(SceneManager* manager) : LevelSceneBase(manager){};
    ~BossScene(){};
    void OnCreate();
    void GoNextScene();
    void SaveProgress();
    void OnLoad();

    void Update();
    void Draw();
};
