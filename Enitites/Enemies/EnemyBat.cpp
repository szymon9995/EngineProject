#include "EnemyBat.h"

#include <math.h>

EnemyBat::EnemyBat(int x,int y,Player *player)
{
    this->x=x;
    this->y=y;
    this->w=16;
    this->h=24;
    this->radius=150;
    this->speed = 2;
    this->player = player;
    j=0;
    i=0;
    AlImage sprite;
    sprite.loadImage("images/Enemies/Bat/Bat_Sprite_Sheet.png");

    for(int j=0;j<3;j++)
        for(int i=0;i<5;i++)
            images[i + (j*5)] = sprite.cropOut(i*16,j*24,16,24);
}

EnemyBat::~EnemyBat()
{

}

void EnemyBat::draw()
{
    images[j].drawScaledImage(x,y,2.0);
    i++;
}

void EnemyBat::update()
{
    if(i==15)
    {
        i=0;
        j++;
        if(j>=5)
        j=0;
    }
    double d = pow(player->x-x,2) + pow(player->y-y,2);

    if( d < pow(radius,2) )
    {
        FloatRect rect(x,y,w,h);
        if(player->x>x)
            x+=speed;
        if(player->x<x)
            x-=speed;
        if(player->y>y)
            y+=speed;
        if(player->y<y)
            y-=speed;
        if(player->pos->Intersect(rect))
        {
            player->OnHit();
        }
    }
    
}