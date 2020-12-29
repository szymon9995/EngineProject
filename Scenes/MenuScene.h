#pragma once

#include "../AlAbstract/Scene.h"
#include "../Engine/SceneManager.h"
#include "../Enitites/UI/Button.h"
#include "../AlClasses/AlConfig.h"

typedef class SceneManager SceneManager;
class MenuScene : public Scene
{
private:
    SceneManager *manager;
    AlConfig saveFile = AlConfig("savedata");
    Button startButton;
    Button loadButton;
    Button exitButton;
    bool saveExits;
public:
    MenuScene(SceneManager *manager);
    ~MenuScene();
    void Draw();//rysowanie obiektow sceny tesowej
    void Update();//uaktualnianie obiektow sceny testowej
    void OnDestroy();//niszczenie sceny testowej i jej obiektow
    void OnCreate();//tworzenie sceny testowej i jej obiektow
    void OnLoad();
    void StartGame();
    void LoadSave();
    void OnExit();
};