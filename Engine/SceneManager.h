#pragma once

#include "EntityContener.h"
#include "../AlAbstract/Scene.h"
#include "../Scenes/TestScene.h"
#include <map>
class SceneManager//Manager scen, przetrzymuje je i laduje zaleznie od poorzeb
{
    
private:
    unsigned int cur_ID;//ID terazniejszej sceny
    std::map<unsigned int,Scene *> sceneList;//mapa scen i ich numeru
    Scene* cur_scene;//terazniejsza/aktywna scena
    bool isEnd;
public:
    SceneManager();//konstruktor
    ~SceneManager();//dekstruktor

    void Update();//uaktualnianie sceny
    void Draw();//rysowanie sceny
    void UnloadScene();//odladowywanie sceny
    void LoadScene(unsigned int sceneNum);//lasowanie sceny
    void CreateFirst();//tworznie(ustawianie) piewrwszej sceny

    void AddScene(Scene *scene,unsigned int num);//dodawanie sceny
    void stopApp();
    bool canEnd();
};