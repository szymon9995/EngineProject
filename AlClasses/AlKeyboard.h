#pragma once
#include <allegro5/allegro.h>
#include <allegro5/keycodes.h>

class AlKeyboard
{
private:
    static ALLEGRO_KEYBOARD_STATE keyboard;
public:
    static void UpdateKeyboard();
    static ALLEGRO_KEYBOARD_STATE GetKeyboard();
    static ALLEGRO_KEYBOARD_STATE* GetKeyboardAdress();

    static bool isKeyPressed(int key);
};

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