#pragma once
#include <allegro5/allegro.h>
#include <allegro5/events.h>
//typedef struct ALLEGRO_EVENT_QUEUE ALLEGRO_EVENT_QUEUE;
//typedef struct ALLEGRO_EVENT_SOURCE ALLEGRO_EVENT_SOURCE;
//typedef struct ALLEGRO_EVENT ALLEGRO_EVENT;


class AlEventQueue//klasas przetrzymujaca kolejke wydarzen
{
private:
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT event;
public:
    void WaitFEvt();//czekanie/ukalualnainie wydarzenia
    void Register(ALLEGRO_EVENT_SOURCE *source);//rejestrowanie zrodel wydarzen
    //
    bool IsEventType(unsigned int eventType);//spawdzanie czy event jest naego typu
    bool IsEventSource(ALLEGRO_EVENT_SOURCE *source);//sprawdzenie czy event jest z danego zrodla
    //Timer
    bool IsTimer();
    
    AlEventQueue();//konstruktor kolejki wydarzen
    ~AlEventQueue();//dekonstruktor kolejki wydarzen
};