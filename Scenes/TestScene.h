#pragma once

#include "../AlAbstract/Scene.h"
#include "../Enitites/Player/Player.h"
#include "../Engine/EntityContener.h"
#include "../Enitites/Tiles/Tile.h"
#include "../Enitites/Enemies/EnemyBat.h"
#include "../Enitites/Enemies/EnemyZombie.h"
#include "../Enitites/UI/HpBar.h"

class TestScene : public Scene
{
private:
    EntityContener contener;//kontener dla tej sceny
    Player player;  //gracz uzywany w tej scenie
public:
    TestScene();//konstruktor testowej sceny
    ~TestScene();//dekonstruktor sceny testowej
    void Draw();//rysowanie obiektow sceny tesowej
    void Update();//uaktualnianie obiektow sceny testowej
    void OnDestroy();//niszczenie sceny testowej i jej obiektow
    void OnCreate();//tworzenie sceny testowej i jej obiektow
};
