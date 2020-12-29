#include "AlMouse.h"

#include <allegro5/allegro.h>
#include "../Type/FloatRect.h"


ALLEGRO_MOUSE_STATE AlMouse::mouse;

void AlMouse::updateMouse()
{
    al_get_mouse_state(&mouse);
}

int AlMouse::getMouseX()
{
    return mouse.x;
}

int AlMouse::getMouseY()
{
    return mouse.y;
}

int AlMouse::getButton()
{
    return mouse.buttons;
}

bool AlMouse::isContained(int x,int y,int w,int h)
{
    if(mouse.x>=x && mouse.x<=(x+w))
    {
        if(mouse.y>=y && mouse.y<=(y+h))
        {
            return true;
        }
    }
    return false;
}