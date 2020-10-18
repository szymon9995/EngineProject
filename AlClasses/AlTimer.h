#pragma once
#include <allegro5/allegro.h>

class AlTimer
{
private:
    ALLEGRO_TIMER *clock;
public:
    void Start();
    void Stop();
    void Resume();
    int GetCount();
    void SetCount(int set);
    void AddCount(int add);
    double GetSpeed();
    void SetSpeed(double speed);
    ALLEGRO_EVENT_SOURCE* TimerEvent();
    ALLEGRO_TIMER* GetTimer();

    AlTimer(double speed);
    ~AlTimer();
};

void AlTimer::Start()
{
    al_start_timer(clock);
}

void AlTimer::Stop()
{
    al_stop_timer(clock);
}

void AlTimer::Resume()
{
    al_resume_timer(clock);
}

int AlTimer::GetCount()
{
    return al_get_timer_count(clock);
}

void AlTimer::SetCount(int set)
{
    al_set_timer_count(clock,set);
}

void AlTimer::AddCount(int add)
{
    al_add_timer_count(clock,add);
}

double AlTimer::GetSpeed()
{
    return al_get_timer_speed(clock);
}

void AlTimer::SetSpeed(double speed)
{
    al_set_timer_speed(clock,speed);
}

ALLEGRO_EVENT_SOURCE* AlTimer::TimerEvent()
{
    return al_get_timer_event_source(clock);
}

ALLEGRO_TIMER* AlTimer::GetTimer()
{
    return clock;
}

AlTimer::AlTimer(double speed)
{
    clock=al_create_timer(speed);
}

AlTimer::~AlTimer()
{
    if(clock!=NULL)
        al_destroy_timer(clock);
}
