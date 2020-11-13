#pragma once

#include <iostream>
#include <allegro5/allegro.h>
#include "../AlClasses/AlInitAll.h"
#include "../AlClasses/AlDisplay.h"
#include "../AlClasses/AlImage.h"
#include "../AlClasses/AlFont.h"
#include "../AlClasses/AlTimer.h"
#include "../AlClasses/AlEventQueue.h"
#include "../AlClasses/AlKeyboard.h"
#include "../AlClasses/AlMouse.h"
#include "../AlClasses/AlDrawable.h"

#include "StartUpConfig.h"
#include "EntityContener.h"

#include "../Editables/RegisterEntities.h"

#include "../Test/Test2.h"
#include "../Enitites/Player/Player.h"

class Engine
{
private:
    bool canBeStarted;

    AlDisplay display;
    StartUpConfig strartup;
    EntityContener contener;


    void LoadStartUp();
    void UpdateDisplay();

    void InitDisplay();
public:
    Engine();
    ~Engine();

    void Start();
};

//Constructors Destructors
Engine::Engine()
{
     //Init allegro,keyboard,mouse,primitives itp i sprawdzenia czy nie ma bledu
    bool test;
    AlInitAll T= AlInitAll(test);
    if(test==false)
    {
        std::cout<<T.ReturnError()<<std::endl;
        canBeStarted = false;
        return;
    }
    canBeStarted=true;
}

void Engine::InitDisplay()
{
    display.SetWindowMode(strartup.getDisplayMode(),strartup.getDisplayIsResizable());
    display.CreateDisplay(strartup.getDisplayWidth(),strartup.getDisplayHeight());   
}

Engine::~Engine()
{
}

//Private

void Engine::UpdateDisplay()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    contener.Draw();
    al_flip_display();
}
//Public

void Engine::Start()
{
    if(!canBeStarted)
        return;
    bool exit = false;
    
    InitDisplay();

    AlTimer timer_fps(1.0/60);
    AlEventQueue main_queue;
    main_queue.Register(timer_fps.TimerEvent());
    main_queue.Register(display.DisplayEvent());

    //
    AlFont font;
    //
    RegisterEntities(contener);

    timer_fps.Start();
    while(!exit)
    {
        AlMouse::updateMouse();
        AlKeyboard::UpdateKeyboard();
        main_queue.WaitFEvt();

        contener.Update();
        if(main_queue.IsEventSource(timer_fps.TimerEvent()))
            UpdateDisplay();

        if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_ESCAPE) || main_queue.IsEventType(ALLEGRO_EVENT_DISPLAY_CLOSE))
            exit=true;
    }
}
