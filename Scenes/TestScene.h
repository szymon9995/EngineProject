#pragma once

#include "../AlAbstract/Scene.h"
#include "../Enitites/Player/Player.h"
#include "../Engine/EntityContener.h"
#include "../Enitites/Tiles/Tile.h"
#include "../Enitites/Enemies/EnemyBat.h"
#include "../Enitites/Enemies/EnemyZombie.h"
#include "../Enitites/UI/HpBar.h"
#include "../Engine/Camera.h"
#include "ScenesConfig.h"
#include "../Enitites/Tiles/DoorTile.h"
#include "../Engine/SceneManager.h"

typedef class SceneManager SceneManager;
class TestScene : public Scene
{
protected:
    EntityContener contener;//kontener dla tej sceny
    Player player;  //gracz uzywany w tej scenie
    Camera camera;
    HpBar hpBar;
    ScenesConfig sceneConfig;
    DoorTile* exitTile;
    SceneManager* manager;
public:
    TestScene(SceneManager* manager);//konstruktor testowej sceny
    ~TestScene();//dekonstruktor sceny testowej
    void Draw();//rysowanie obiektow sceny tesowej
    void Update();//uaktualnianie obiektow sceny testowej
    void OnDestroy();//niszczenie sceny testowej i jej obiektow
    void OnCreate();//tworzenie sceny testowej i jej obiektow
    void CreateTiles(std::string scene_name);
    void SetEnemies(std::string scene_name);
    void SetPlayer(std::string scene_name);
    void SetUI(std::string scene_name);

    void GoNextScene();
};
