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

#include "StartUpConfig.h"
#include "EntityContener.h"

#include "../Test/Test2.h"

class Engine
{
private:
    bool canBeStarted;

    AlDisplay display;
    StartUpConfig strartup;
    AlMouse mouse;
    AlKeyboard keyboard;
    EntityContener contener;


    void LoadStartUp();
    void UpdateDisplay();
public:
    Engine();
    ~Engine();

    void Start();
    void Test();
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

Engine::~Engine()
{
}

//Private

void Engine::UpdateDisplay()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));

    al_flip_display();
}
//Public

void Engine::Start()
{
    if(!canBeStarted)
        return;
    bool exit = false;
    AlTimer timer_fps(1.0/60);

    display.CreateDisplay(strartup.getDisplayWidth(),strartup.getDisplayHeight());

    AlEventQueue main_queue;
    main_queue.Register(timer_fps.TimerEvent());

    timer_fps.Start();
    while(!exit)
    {

    }
}

void Engine::Test()
{
    if(!canBeStarted)
        return;

    display.CreateDisplay(strartup.getDisplayWidth(),strartup.getDisplayHeight());

    //robienie image (dodac lepsze postepowanie kiedy nie mozna zaladowac obrazu)
    AlImage image=AlImage("images/test.png");

    //ladowanie fonta automatycznego
    AlFont font = AlFont();
    //oraz comic sans fonta
    AlFont comic_sans_font("fonts/comic.ttf",16,1);

    //timer (pamietac dodac wyjatek przzy tworzeniu jezeli czas jest rowny 0)
    AlTimer timer_draw = AlTimer(1.0/20);
    AlTimer timer_tmp =AlTimer(5.0);

    //Tworzy kolejke wydarzen
    AlEventQueue main_queue;
    main_queue.Register(timer_draw.TimerEvent());
    main_queue.Register(timer_tmp.TimerEvent());

    
    bool exit = false;

    ALLEGRO_EVENT event_al;

    Test2 test = Test2();
    contener.Register(test);

    timer_draw.Start();
    timer_tmp.Start();

    while(!exit)
    {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        /*
        al_draw_bitmap(image.GetBitmap(),20,20,0);

        al_draw_text(comic_sans_font.GetFont(),al_map_rgb(255,255,0),400,400,ALLEGRO_ALIGN_CENTER,"Test Comic!");
        comic_sans_font.DrawText(al_map_rgb(255,255,0),400,400,ALLEGRO_ALIGN_CENTER,"Test Comic!");
        al_draw_text(font.GetFont(),al_map_rgb(255,255,0),400,500,ALLEGRO_ALIGN_CENTER,"Test Default!");
*/
         al_draw_textf(font.GetFont(),al_map_rgb(255,255,0),400,500,ALLEGRO_ALIGN_CENTER,"Amount:%d",0);
        contener.Draw();
        contener.Update();

        main_queue.WaitFEvt(&event_al);

        if(event_al.type == ALLEGRO_EVENT_TIMER)
		{
			if(event_al.timer.source == timer_tmp.GetTimer())
			{
				exit=true;
			}
            if(event_al.timer.source == timer_draw.GetTimer())
            {
                mouse.updateMouse();
                std::cout<<"Mouse x:"<<mouse.getMouseX()<<" y:"<<mouse.getMouseY()<<std::endl;
            }
		}

        al_flip_display();
    }
}
