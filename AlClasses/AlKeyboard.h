#pragma once
#include <allegro5/keycodes.h>

typedef struct ALLEGRO_KEYBOARD_STATE ALLEGRO_KEYBOARD_STATE;

class AlKeyboard//kalsa do czytania klawiatury
{
private:
    static ALLEGRO_KEYBOARD_STATE keyboard;
public:
    static void UpdateKeyboard();//aktualizacja klawiatury
    static ALLEGRO_KEYBOARD_STATE GetKeyboard();//dostatnie stanu klawiatury
    static ALLEGRO_KEYBOARD_STATE* GetKeyboardAdress();//dostanie adresu na stan klawiatury

    static bool isKeyPressed(int key);//spawdzenie czy guzik jest nacisniety
};