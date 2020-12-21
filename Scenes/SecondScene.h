#pragma once

#include "TestScene.h"

class SecondScene : public TestScene
{
private:
public:
    SecondScene(SceneManager* manager) : TestScene(manager){};
    ~SecondScene();
    void OnCreate();
    void GoNextScene();
};
