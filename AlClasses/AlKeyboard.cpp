#include "AlKeyboard.h"

#include <allegro5/allegro.h>

ALLEGRO_KEYBOARD_STATE AlKeyboard::keyboard;

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

bool AlKeyboard::isKeyPressed(int key)
{
    return al_key_down(&keyboard,key);
}
