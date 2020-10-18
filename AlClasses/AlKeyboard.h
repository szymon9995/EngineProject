#pragma once
#include <allegro5/allegro.h>

class AlKeyboard
{
private:
    ALLEGRO_KEYBOARD_STATE keyboard;
public:
    void UpdateKeyboard();
    ALLEGRO_KEYBOARD_STATE GetKeyboard();
    ALLEGRO_KEYBOARD_STATE* GetKeyboardAdress();
};

void AlKeyboard::UpdateKeyboard()
{
    al_get_keyboard_state(&keyboard);
}

ALLEGRO_KEYBOARD_STATE AlKeyboard::GetKeyboard()
{
    return keyboard;
}

ALLEGRO_KEYBOARD_STATE* AlKeyboard::GetKeyboardAdress()
{
    return &keyboard;
}