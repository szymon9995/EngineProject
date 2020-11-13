#pragma once
#include <allegro5/allegro.h>

class AlMouse
{
private:
    static ALLEGRO_MOUSE_STATE mouse;
public:
    enum Button
    {
        RClick=1,
        LClick=2,
        R_LClick=3,
        MClick=4,
        R_MClick=5,
        L_MClick=6,
        R_L_MClick=7
        ////////////////
    };
    static void updateMouse();
    static int getMouseX();
    static int getMouseY();
    static int getButton();
};

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