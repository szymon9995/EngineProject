#pragma once

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


class Engine
{
private:

public:
    Engine();
    ~Engine();

    void Start();
};

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Start()
{
    bool test;
    AlInitAll T= AlInitAll(test);
    if(test==false)
    {
        std::cout<<T.ReturnError()<<std::endl;
        return;
    }
}