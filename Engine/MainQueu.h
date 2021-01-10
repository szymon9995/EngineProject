#pragma once

#include "../AlClasses/AlEventQueue.h"
#include "../AlClasses/AlTimer.h"

class MainQueu
{
private:
    static AlEventQueue* queu;
public:
    MainQueu();
    ~MainQueu();
    
    static void setQueu(AlEventQueue* queuM);
    static AlEventQueue* getQuee();
    static void regTimer(AlTimer *timer);

};
