#pragma once
#include <allegro5/allegro.h>

class AlDisplay
{
private:    
    ALLEGRO_DISPLAY *display;
public:
    AlDisplay(int w,int h)
    {
        display = al_create_display(w,h);
    };
    ~AlDisplay()
    {
        if(display!=NULL)
            al_destroy_display(display);
    }
};