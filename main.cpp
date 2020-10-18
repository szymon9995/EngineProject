#include <iostream>
#include <allegro5/allegro.h>
#include "AlClasses/AlInitAll.h"
#include "AlClasses/AlDisplay.h"
#include "AlClasses/AlImage.h"
#include "AlClasses/AlFont.h"
#include "AlClasses/AlTimer.h"
#include "AlClasses/AlEventQueue.h"
#include "AlClasses/AlKeyboard.h"
#include "AlClasses/AlMouse.h"
#include "AlClasses/AlConfig.h"

using namespace std;

int main()
{

    //Init allegro,keyboard,mouse,primitives itp i sprawdzenia czy nie ma bledu
    bool test;
    AlInitAll T= AlInitAll(test);
    if(test==false)
    {
        cout<<T.ReturnError()<<endl;
        return -1;
    }

    //config file
    AlConfig config;

    //robienie display
    AlDisplay display(800,600);

    //robienie image (dodac lepsze postepowanie kiedy nie mozna zaladowac obrazu)
    AlImage image=AlImage("images/test.png");

    //ladowanie fonta automatycznego
    AlFont font = AlFont();
    //oraz comic sans fonta
    AlFont comic_sans_font("fonts/comic.ttf",16,0);

    //tworzy klawiature
    AlKeyboard keyboard;
    
    //timer (pamietac dodac wyjatek przzy tworzeniu jezeli czas jest rowny 0)
    AlTimer timer_draw = AlTimer(1.0/20);
    AlTimer timer_tmp =AlTimer(5.0);

    //Tworzy kolejke wydarzen
    AlEventQueue main_queue;
    main_queue.Register(timer_draw.TimerEvent());
    main_queue.Register(timer_tmp.TimerEvent());

    //Tworzy myszke
    AlMouse mouse;

    bool exit = false;

    ALLEGRO_EVENT event_al;

    timer_draw.Start();
    timer_tmp.Start();

    while(!exit)
    {
        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_draw_bitmap(image.GetBitmap(),20,20,0);

        al_draw_text(comic_sans_font.GetFont(),al_map_rgb(255,255,0),400,400,ALLEGRO_ALIGN_CENTER,"Test Comic!");

        al_draw_text(font.GetFont(),al_map_rgb(255,255,0),400,500,ALLEGRO_ALIGN_CENTER,"Test Default!");
        
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

    al_create_config();

    return 0;
}
