#include "MenuScene.h"

#include "../AlClasses/AlKeyboard.h"
#include "SaveConfig.h"

MenuScene::MenuScene(SceneManager *manager)
{
    this->manager=manager;
}

MenuScene::~MenuScene()
{
    OnDestroy();
}

void MenuScene::Draw()
{
    startButton.draw();
    exitButton.draw();
    loadButton.draw();
}

void MenuScene::Update()
{
    if(startButton.isClicked())
        StartGame();
    if(exitButton.isClicked() || AlKeyboard::isKeyPressed(ALLEGRO_KEY_ESCAPE))
        OnExit();
    if(loadButton.isClicked())
        LoadSave();
}

void MenuScene::OnCreate()
{

    startButton.setFont("fonts/comic.ttf",40);
    startButton.setText("Start");
    startButton.setSize(200,50,400,100);
    startButton.setColor(BLUE);

    loadButton.setFont("fonts/comic.ttf",40);
    loadButton.setText("Load Save");
    loadButton.setSize(200,250,400,100);
    loadButton.setColor(BLUE);

    exitButton.setFont("fonts/comic.ttf",40);
    exitButton.setText("Exit");
    exitButton.setSize(200,440,400,100);
    exitButton.setColor(BLUE);

    SaveConfig::initSave();
    
}

void MenuScene::OnDestroy()
{   
    SaveConfig::endSave();
}

void MenuScene::StartGame()
{
    manager->LoadScene(1);
}

void MenuScene::LoadSave()
{
    if(saveExits)
    {
        std::cout<<"Load Save"<<std::endl;
        int scene = SaveConfig::getScene();
        SaveConfig::loadProgress();
        manager->LoadScene(scene);
    }
    
}

void MenuScene::OnExit()
{
    manager->stopApp();
}

void MenuScene::OnLoad()
{
   
    if(SaveConfig::getScene()==-1)
        saveExits=false;
    else
        saveExits=true;
    
    if(!saveExits)
        loadButton.setTextColor(GREY);
    else
        loadButton.setTextColor(YELLOW);
}