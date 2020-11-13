#pragma once
#include <allegro5/allegro.h>

class AlDisplay
{
private:    
    ALLEGRO_DISPLAY *display;
    int flags;
public:

    AlDisplay();
    ~AlDisplay();

    void CreateDisplay(int w,int h);
    void SetWindowMode(bool isFullScreen,bool isResizable);
    int getDisplayWidth();
    int getDisplayHeight();
    ALLEGRO_EVENT_SOURCE* DisplayEvent();

};

AlDisplay::AlDisplay()
{
    flags=-1;
}

AlDisplay::~AlDisplay()
{
    if(display!=NULL)
            al_destroy_display(display);
}

void AlDisplay::CreateDisplay(int w,int h)
{
        if(flags!=-1)
            al_set_new_display_flags(flags);
        display = al_create_display(w,h);
}

 void AlDisplay::SetWindowMode(bool isFullScreen,bool isResizable)
 {
     if(isFullScreen)
            flags = ALLEGRO_FULLSCREEN;
        else
            flags = ALLEGRO_WINDOWED;

    if(isResizable)
            flags += ALLEGRO_RESIZABLE;
 }

int AlDisplay::getDisplayWidth()
{
    return al_get_display_width(display);
}

int AlDisplay::getDisplayHeight()
{
    return al_get_display_height(display);
}

ALLEGRO_EVENT_SOURCE* AlDisplay::DisplayEvent()
{
    return al_get_display_event_source(display);
}