#pragma once
#include <allegro5/allegro.h>

class AlEventQueue
{
private:
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT event;
public:
    void WaitFEvt();
    void Register(ALLEGRO_EVENT_SOURCE *source);
    //
    bool IsEventType(unsigned int eventType);
    bool IsEventSource(ALLEGRO_EVENT_SOURCE *source);
    //Timer
    bool IsTimer();
    
    AlEventQueue();
    ~AlEventQueue();
};

void AlEventQueue::WaitFEvt()
{
    al_wait_for_event(queue,&event);
}

void AlEventQueue::Register(ALLEGRO_EVENT_SOURCE *source)
{
    al_register_event_source(queue,source);
}

bool AlEventQueue::IsEventType(unsigned int eventType)
{
    return (event.type == eventType);
}

bool AlEventQueue::IsEventSource(ALLEGRO_EVENT_SOURCE *source)
{
    return (event.any.source == source);
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
