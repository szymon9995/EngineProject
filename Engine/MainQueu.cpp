#include "MainQueu.h"

#include <iostream>

AlEventQueue* MainQueu::queu = NULL;

MainQueu::MainQueu()
{
}

MainQueu::~MainQueu()
{
}

void MainQueu::setQueu(AlEventQueue* queuM)
{
    queu=queuM;
}

AlEventQueue* MainQueu::getQuee()
{
    return queu;
}

void MainQueu::regTimer(AlTimer *timer)
{
    queu->Register(timer->TimerEvent());
}