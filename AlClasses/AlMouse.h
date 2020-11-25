#pragma once

typedef struct ALLEGRO_MOUSE_STATE ALLEGRO_MOUSE_STATE;

class AlMouse//klasa do czytania myszki
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
    static void updateMouse();//auktualizacja myszki
    static int getMouseX();//dostanie wpolrzednych x myszki
    static int getMouseY();//dostanie wsporzednych y myszki
    static int getButton();//dostanie numer zacisietego guzika
};