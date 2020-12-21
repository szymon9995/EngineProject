#pragma once

#include "TestScene.h"

class BossScene : public TestScene
{
private:
    
public:
    BossScene(SceneManager* manager) : TestScene(manager){};
    ~BossScene(){};
    void OnCreate();
    void GoNextScene();
};
