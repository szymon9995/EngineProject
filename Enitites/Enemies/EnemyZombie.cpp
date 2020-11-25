#include "EnemyZombie.h"

EnemyZombie::EnemyZombie(int x,int y,int x2,Player *player)
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
    this->player=player;
}

EnemyZombie::~EnemyZombie()
{
}

void EnemyZombie::draw()
{
    images[0].drawScaledImage(x,y,2.0);
}

void EnemyZombie::update()
{
    
    if(reverse==false)
        x+=speed;
    else
        x-=speed;

    if(x>x2)
        reverse=true;
    else if(x<x1)
        reverse=false;
    FloatRect rect(x,y,32,32);
    if(player->pos->Intersect(rect))
    {
        player->OnHit();
    }
    
}
