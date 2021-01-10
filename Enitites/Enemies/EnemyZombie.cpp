#include "EnemyZombie.h"

EnemyZombie::EnemyZombie(int x,int y,int x2,int w,int h,Player *player)
{
    AlImage zombie;
    zombie.loadImage("images/Enemies/Zombie/zombie_run.png");
    for(int i=0;i<4;i++)
        images[i] = zombie.cropOut(i*32,0,32,32);
    reverse = false;
    this->x=x;
    this->y=y;
    this->x1=x;
    this->x2=x2;
    this->speed=2;
    this->w=w;
    this->h=h;
    this->player=player;
}

EnemyZombie::~EnemyZombie()
{
}

void EnemyZombie::draw()
{
    if(isAlive)
    {
        if(!reverse)
            images[0].drawScaledImage(x,y,w+(w/3),h+(h/3));
        else
            images[0].drawReversedScaledImage(x,y,w+(w/3),h+(h/3));
    }
        
}

void EnemyZombie::update()
{
    if(isAlive)
    {

    if(reverse==false)
        x+=speed;
    else
        x-=speed;

    if(x>x2)
        reverse=true;
    else if(x<x1)
        reverse=false;
    FloatRect rect(x,y,w,h);
    if(player->pos->Intersect(rect))
    {
        player->OnHit(1);
    }
    if(player->attackBox->Intersect(rect) && player->isAttacking())
    {
        isAlive=false;
    }
    }
}
