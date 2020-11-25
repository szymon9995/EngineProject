#include "Player.h"

Player::Player() 
{
    
}

void Player::LoadPlayer(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->xp=x;
    this->yp=y;

    this->atk =3;
    this->hp=3;
    this->max_spd =5;
    this->invincible = false;
    
    this->jump=0;
    this->activate_gravity=true;

    font.LoadDefaultFont();
    pos = new FloatRect(x,y,w,h);
    prev_pos = new FloatRect(x,y,w,h);
}

Player::~Player()
{
    if(pos!=NULL)
        delete pos;
    if(prev_pos!=NULL)
        delete prev_pos;
}

void Player::update()
{
    xp=x;
    yp=y;
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_A))
        x-=max_spd;
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_D))
        x+=max_spd;
    //if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_W))
        //y-=max_spd;
    //if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_S))
        //y+=max_spd;
    //if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_F))
        //Attack();
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_SPACE) && activate_gravity==false)
        Jump();
    if(activate_gravity==true)
    {
        y-=jump;
        jump-=gravity;
        if(jump<-max_spd)
            jump=-max_spd;
    }

    delete pos;
    delete prev_pos;

    pos = new FloatRect(x,y,w,h);
    prev_pos = new FloatRect(xp,yp,w,h);
}

void Player::draw()
{
    AlDrawable::drawFilledRectangle(x,y,x+w,y+h,255,0,0);
    font.drawText(YELLOW,x+(w/2),y+(h/2),"X:%d,Y:%d",x,y);
}

void Player::OnHit()
{
    if(invincible==false)
    {
        invincible=true;
        hp=hp-1;
    }
}

void Player::Jump()
{
    activate_gravity = true;
    jump = max_spd;
}

void Player::DeactiveGravity()
{
    activate_gravity = false;
}

int Player::getHp()
{
    return hp;
}