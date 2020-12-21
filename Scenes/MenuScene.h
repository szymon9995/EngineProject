#pragma once

#include "../AlAbstract/Scene.h"

class MenuScene
{
private:
    
public:
    MenuScene();
    ~MenuScene();
    void Draw();//rysowanie obiektow sceny tesowej
    void Update();//uaktualnianie obiektow sceny testowej
    void OnDestroy();//niszczenie sceny testowej i jej obiektow
    void OnCreate();//tworzenie sceny testowej i jej obiektow
};