#include "BossParticle.h"

BossParticle::BossParticle()
{
    AlImage tmp;
    tmp.loadImage("images/Enemies/Boss/summonIdle.png");
    particle = tmp.cropOut(17,17,15,30);
    isMoving = false;
}

BossParticle::~BossParticle()
{
}


void BossParticle::setCord(int x,int y)
{
    this->x=x;
    this->y=y;
}

void BossParticle::setProp(int x,int y,int w,int h,Player *player)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;

    this->player=player;
}

void BossParticle::Move()
{
    if(x<xdest)
    {
        x+=speed;
        if(x>xdest)
            x=xdest;
    }
        
    if(x>xdest)
    {
        x-=speed;
        if(x<xdest)
            x=xdest;
    }

    if(y<ydest)
    {
        y+=speed;
        if(y>ydest)
            y=ydest;
    }
        
    if(y>ydest)
    {
        y-=speed;
        if(y<ydest)
            y=ydest;
    }

    if(y==ydest && x==xdest)
        isMoving=false;
        
}

void BossParticle::update()
{
    if(isAlive)
    {
        FloatRect hitbox(x,y,w,h);
        if(player->pos->Intersect(hitbox))
        {
            player->OnHit(1);
        }
        if(isMoving)
        {
            Move();
        }
    }
}

void BossParticle::draw()
{
    if(isAlive)
        particle.drawScaledImage(x,y,w,h);
}

void BossParticle::goToDest(int x,int y)
{
    xdest=x;
    ydest=y;
    isMoving=true;
}

void BossParticle::goToDest2(int x,int y)
{
    int tmpx = std::abs(this->x-x);
    int tmpy = std::abs(this->y-y);

    xdest = x+tmpx;
    ydest = y+tmpy;
    isMoving=true;
}