#pragma once
#include <allegro5/allegro.h>

class AlEventQueue
{
private:
    ALLEGRO_EVENT_QUEUE *queue;
public:
    void WaitFEvt(ALLEGRO_EVENT *event);
    void Register(ALLEGRO_EVENT_SOURCE *source);
    
    AlEventQueue();
    ~AlEventQueue();
};

void AlEventQueue::WaitFEvt(ALLEGRO_EVENT *event)
{
    al_wait_for_event(queue,event);
}

void AlEventQueue::Register(ALLEGRO_EVENT_SOURCE *source)
{
    al_register_event_source(queue,source);
}

AlEventQueue::AlEventQueue()
{
    queue=al_create_event_queue();
}

AlEventQueue::~AlEventQueue()
{
    if(queue!=NULL)
        al_destroy_event_queue(queue);
}
