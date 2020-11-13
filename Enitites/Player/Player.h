#pragma once

#include "../../AlAbstract/Entity.h"
#include "../../AlClasses/AlKeyboard.h"
#include "../../AlClasses/AlDrawable.h"

class Player : public Entity {
    private:
        int atk, def; 
        double max_spd, jump;
    public:

        Player(int x, int y, int w, int h, int atk, int def, int max_spd, int jump_power);
        void update();
        void draw();
        void Walk();
        void Attack(int attack_keycode);
        bool Impact();
        void Jump();
        void Interact(int interact_keycode);
};

Player::Player(int x, int y, int w, int h, int atk, int def, int max_spd, int jump_power) 
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;

    this->atk = atk;
    this->def = def;
    this->max_spd = max_spd;
    this->jump = jump_power;
}

void Player::update()
{
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_A))
        x-=max_spd;
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_D))
        x+=max_spd;
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_W))
        y-=max_spd;
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_S))
        y+=max_spd;
}

void Player::draw()
{
    AlDrawable::drawFilledRectangle(x,y,x+w,y+h,255,0,0);
}
/*
void Player::Walk() 
{
    
    double speed = 0;
    //if(event.type == ALLEGRO_EVENT_TIMER) {
        if(1)
        {
            //poruszanie sie w lewo z przyspieszeniem od 1 do wartosci spd
        }
        if(1)
        {
            //poruszanie sie w prawo z przyspieszeniem od 1 do wartosci spd
        }
    //}
    
}

void Player::Attack(int attack_keycode) 
{
    
    ALLEGRO_EVENT event;
    ev_q.WaitFEvt(event);
    al_get_keyboard_state(kb.GetKeyboardAddress());
    if(event.type == ALLEGRO_EVENT_TIMER) {
        if(al_key_down(kb.GetKeyboardAddress(),attack_keycode)) {
            //atak z sila atk
        }
    }
    
}

bool Player::Impact() 
{
    return false; //na razie zwraca false, ale chodzi o dotkniecie przeciwnika
}

void Player::Jump() 
{
    
    double jump_speed = 0;
    ALLEGRO_EVENT event;
    ev_q.WaitFEvt(event);
    al_get_keyboard_state(kb.GetKeyboardAddress());
    if(event.type == ALLEGRO_EVENT_TIMER) {
        if(al_key_down(kb.GetKeyboardAddress(),ALLEGRO_KEY_UP) || al_key_down(kb.GetKeyboardAddress(),ALLEGRO_KEY_W)){
            //skok zaczynajacy sie z sila jump_power
        }
    }
    
}

//void Player::Interact(int interact_keycode) {
    
    ALLEGRO_EVENT event;
    ev_q.WaitFEvt(event);
    al_get_keyboard_state(kb.GetKeyboardAddress());
    if(event.type == ALLEGRO_EVENT_TIMER) {
        if(al_key_down(kb.GetKeyboardAddress(),interact_keycode)){
            //interakcja
        }
    }
    
}*/
