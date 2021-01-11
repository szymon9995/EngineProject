#include "Player.h"

Player::Player()
{
    AlImage tmp;
    tmp.loadImage("images/Player/_side idle.png");
    playerImage = tmp.cropOut(0,0,64,64);
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
    attackBox = new FloatRect(x+w,y,w,h);
    isAttack=false;
    isCoolDown = false;
    dir=lastdir=LEFT;

    isAlive=true;

    MainQueu::getQuee()->Register(attackTimer.TimerEvent());
    MainQueu::getQuee()->Register(invincibleTimer.TimerEvent());
    MainQueu::getQuee()->Register(attackCoolDown.TimerEvent());
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
    if(!isAlive)
        return;
    xp=x;
    yp=y;
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_A))
    {
        x-=max_spd;
        dir=LEFT;
    }
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_D))
    {
        x+=max_spd;
        dir=RIGHT;
    }
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_W))
        dir=UP;
        //y-=max_spd;
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_S))
        dir=DOWN;
        //y+=max_spd;
    if(AlKeyboard::isKeyPressed(ALLEGRO_KEY_F))
    {
        if(!isAttack && !isCoolDown)
        {
            isAttack=true;
            attackTimer.Start();
        }
    }
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
    delete attackBox;

    pos = new FloatRect(x,y,w,h);
    prev_pos = new FloatRect(xp,yp,w,h);
    if(dir==RIGHT)
        attackBox = new FloatRect(x+w,y,w,h);
    else if(dir==LEFT)
        attackBox = new FloatRect(x-w,y,w,h);
    else if(dir==UP)
        attackBox = new FloatRect(x,y-h,w,h);
    else if(dir==DOWN)
        attackBox = new FloatRect(x,y+h,w,h);
    ActiveGravity();

    AttackCoolDown();
    Attack();
    Invincibility();
}

void Player::draw()
{
    if(!invincible)
        AlDrawable::drawFilledRectangle(x,y,x+w,y+h,255,0,0);
    else
        AlDrawable::drawFilledRectangle(x,y,x+w,y+h,0,255,0);

    //playerImage.drawImage(x,y);

    font.drawText(YELLOW,x+(w/2),y+(h/2),"X:%d,Y:%d",x,y);
    if(isAttack)
    {
        if(dir==RIGHT)
            AlDrawable::drawRectangle(x+w,y,x+w+w,y+h,RED,2);
        else if(dir==LEFT)
            AlDrawable::drawRectangle(x,y,x-w,y+h,RED,2);
        else if(dir==UP)
            AlDrawable::drawRectangle(x,y,x+w,y-h,RED,2);
        else if(dir==DOWN)
            AlDrawable::drawRectangle(x,y+h,x+w,y+h+h,RED,2);
    }

}

void Player::OnHit(int hpDamage)
{
    if(invincible==false)
    {
        invincibleTimer.Start();
        invincible=true;
        hp=hp-hpDamage;
        if(hp<0)
            hp=0;
        if(hp==0)
            isAlive=false;
    }
}

void Player::OnHitIgnoreInvic(int hpDamage)
{
    hp=hp-hpDamage;
    if(hp<0)
        hp=0;
    if(hp==0)
        isAlive=false;
}

void Player::Jump()
{
    activate_gravity = true;
    jump = max_spd;
}

void Player::Attack()
{
    if(isAttack)
    {
        dir=lastdir;
        if(MainQueu::getQuee()->IsEventSource(attackTimer.TimerEvent()))
        {
            isAttack=false;
            attackTimer.Stop();
            attackCoolDown.Start();
            isCoolDown=true;
        }
    }
    lastdir=dir;
}

void Player::Invincibility()
{
    if(invincible)
        if(MainQueu::getQuee()->IsEventSource(invincibleTimer.TimerEvent()))
        {
            invincible=false;
            invincibleTimer.Stop();
        }
}

void Player::AttackCoolDown()
{
    if(isCoolDown)
    {
        if(MainQueu::getQuee()->IsEventSource(attackCoolDown.TimerEvent()))
        {
            attackCoolDown.Stop();
            isCoolDown=false;
        }
    }
}

void Player::DeactiveGravity()
{
    activate_gravity = false;
}

void Player::ActiveGravity()
{
    activate_gravity = true;
}

int Player::getHp()
{
    return hp;
}

bool Player::isAttacking()
{
    return isAttack;
}
