#include "AlMouse.h"

#include <allegro5/allegro.h>


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