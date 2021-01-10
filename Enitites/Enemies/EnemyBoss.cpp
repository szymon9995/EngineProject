#include "EnemyBoss.h"

EnemyBoss::EnemyBoss(int x,int y,int w,int h,Player* player)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->player=player;
    AlImage sprite;
    sprite.loadImage("images/Enemies/Boss/idle.png");
    image = sprite.cropOut(33,20,47,63);
    side = RIGHT;
    toSide = LEFT;

    posL[0]=0;posL[1]=0;
    posM[0]=0;posM[1]=0;
    posR[0]=0;posR[1]=0;

    attackEnd = true;

    for(int i=0;i<4;i++)
    {
        particles[i].setProp(-1000,-1000,50,50,player);
    }
    partInt=0;
    setHpDefault();

    MainQueu::getQuee()->Register(moveCoolDown.TimerEvent());
    MainQueu::getQuee()->Register(sendParticleCoolDown.TimerEvent());
    MainQueu::getQuee()->Register(invincibility.TimerEvent());

    invincible=false;
}

EnemyBoss::~EnemyBoss()
{
}

void EnemyBoss::update()
{
    if(isAlive)
    {
        AttackAndMovement();
        for(int i=0;i<4;i++)
            particles[i].update();
        FloatRect hitbox(x,y,w,h);
        if(!invincible && player->pos->Intersect(hitbox))
        {
            invincibility.Start();
            invincible=true;
            hp=hp-1;
            if(hp==0)
                isAlive=false;
        }
        if(invincible)
        {
            if(MainQueu::getQuee()->IsEventSource(invincibility.TimerEvent()))
            {
                invincibility.Stop();
                invincible=false;
            }
        }
    }
}

void EnemyBoss::draw()
{
    if(isAlive)
    {
        image.drawScaledImage(x,y,w,h);
        for(int i=0;i<4;i++)
            particles[i].draw();
    }
    
}

void EnemyBoss::setRML(int rx,int ry,int mx,int my,int lx,int ly)
{
    posL[0]=lx; posM[0]=mx; posR[0]=rx;
    posL[1]=ly; posM[1]=my; posR[1]=ry;
}

void EnemyBoss::AttackAndMovement()
{
    int speedY=3,speedX=5;
        if(side==LEFT || side==RIGHT)
        {
            if(attackEnd)
            {
                ToPoint(posM,speedX,speedY);
                if(y==posM[1] && x==posM[0])
                {
                    side = MIDDLE;
                    attackEnd=false;

                    moveCoolDown.Start();
                }
            }
            else
            {
                if(MainQueu::getQuee()->IsEventSource(sendParticleCoolDown.TimerEvent()))
                {
                    particles[partInt].goToDest2(player->x,player->y);
                    partInt++;
                    if(partInt==4)
                    {
                        sendParticleCoolDown.Stop();
                        partInt=0;
                    }
                }
                if(MainQueu::getQuee()->IsEventSource(moveCoolDown.TimerEvent()))
                {
                    attackEnd=true;
                    moveCoolDown.Stop();
                }
                    
            }
            
        }
        else if(side==MIDDLE)
        {
            if(attackEnd)
            {
                if(toSide==LEFT)
                {
                    ToPoint(posL,speedX,speedY);
                    if(y==posL[1] && x==posL[0])
                    {
                        side = toSide;
                        toSide = RIGHT;
                        attackEnd = false;

                        SpawnParticles();

                        moveCoolDown.Start();
                        sendParticleCoolDown.Start();
                    }
                }
                else if(toSide==RIGHT)
                {
                    ToPoint(posR,speedX,speedY);
                    if(y==posR[1] && x==posR[0])
                    {
                        side = toSide;
                        toSide = LEFT;
                        attackEnd = false;

                        SpawnParticles();

                        moveCoolDown.Start();
                        sendParticleCoolDown.Start();
                    }
                }
            }
            else
            {
                if(MainQueu::getQuee()->IsEventSource(moveCoolDown.TimerEvent()))
                {
                    attackEnd=true;
                    moveCoolDown.Stop();
                }
            }
            
        }
}

void EnemyBoss::ToPoint(int point[2],int xSpeed,int ySpeed)
{
    if(x>point[0])
    {
        x-=xSpeed;
        if(x<point[0])
            x=point[0];
    }
    else if(x<point[0])
    {
        x+=xSpeed;
        if(x>point[0])
            x=point[0];
    }
    if(y>point[1])
    {
        y-=ySpeed;
        if(y<point[1])
            y=point[1];
    }
    else if(y<point[1])
    {
        y+=ySpeed;
        if(y>point[1])
            y=point[1];
    }
}

int EnemyBoss::getHp()
{
    return hp;
}

void EnemyBoss::setHpDefault()
{
    hp=20;
    isAlive=true;
}

void EnemyBoss::SpawnParticles()
{
    particles[0].setCord(x-(w/2),y);
    particles[1].setCord(x+w+(w/4),y);
    particles[2].setCord(x-(w/2),y+h);
    particles[3].setCord(x+w+(w/4),y+h);
}