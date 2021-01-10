#pragma once

#include "../../AlAbstract/Entity.h"
#include "../Player/Player.h"
#include "../../Type/FloatRect.h"
#include "../../AlClasses/AlDrawable.h"
#include "../../AlClasses/AlImage.h"
#include "BossParticle.h"

class EnemyBoss : public Entity
{
private:

    enum SIDE
    {
        LEFT,MIDDLE,RIGHT
    };
    int x,y;
    int w,h;
    Player* player;
    AlImage image;
    SIDE side;
    SIDE toSide;
    bool attackEnd;
    BossParticle particles[4];
    int partInt;
    
    int hp;
    int posR[2],posM[2],posL[2];

    AlTimer moveCoolDown = AlTimer(8.0);
    AlTimer sendParticleCoolDown = AlTimer(1.2);
    AlTimer invincibility = AlTimer(0.5);
    bool invincible;

    void ToPoint(int point[2],int xSpeed,int ySpeed);
    void AttackAndMovement();

    void SpawnParticles();
public:
    EnemyBoss(int x,int y,int w,int h,Player* player);
    ~EnemyBoss();

    void setRML(int rx,int ry,int mx,int my,int lx,int ly);
    
    void draw();
    void update();
    int getHp();
    void setHpDefault();
};
