#pragma once
#include "../../AlAbstract/Entity.h"
#include "../../Type/FloatRect.h"
#include "../../AlClasses/AlDrawable.h"
#include "../../AlClasses/AlImage.h"
#include "../Player/Player.h"

class BossParticle : public Entity
{
private:
    int x,y;
    int w,h;
    AlImage particle;
    bool isMoving;

    int xdest,ydest;
    int speed = 3;

    Player *player;
    void Move();
public:
    BossParticle();
    ~BossParticle();

    void setCord(int x,int y);
    void setProp(int x,int y,int w,int h,Player *player);
    void goToDest(int x,int y);
    void goToDest2(int x,int y);

    void draw();
    void update();
};
