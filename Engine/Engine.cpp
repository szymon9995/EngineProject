#include "Engine.h"
#include "MainQueu.h"

//Constructors Destructors

Engine* Engine::engine = NULL;

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
    manager.Draw();
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

    MainQueu::setQueu(&main_queue);
    
    manager.CreateFirst();

    

    bool canUpdate = false;
    timer_fps.Start();

    while(!exit)
    {

        main_queue.WaitFEvt();


        if(main_queue.IsEventSource(timer_fps.TimerEvent()))
            canUpdate=true;
        if(canUpdate)
        {
            AlMouse::updateMouse();
            AlKeyboard::UpdateKeyboard();

            manager.Update();
            UpdateDisplay();

            if(main_queue.IsEventType(ALLEGRO_EVENT_DISPLAY_CLOSE) || manager.canEnd())
            exit=true;
        }



    }
}

Engine* Engine::getEngine()
{
    if(engine==NULL)
    {
        engine = new Engine();
    }
    return engine;
}

void Engine::destroyEngine()
{
    if(engine!=NULL)
    {
        delete engine;
    }
}
