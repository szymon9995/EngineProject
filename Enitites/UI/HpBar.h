#pragma once

#include "../../AlAbstract/Entity.h"
#include"../Player/Player.h"
#include "../../AlClasses/AlDrawable.h"
#include "../../AlClasses/AlFont.h"
#include "../../AlClasses/AlImage.h"

class HpBar : public Entity
{
private:
    int x,y;
    int w,h;
    AlFont font;
    Player *player;
    AlImage heart;
public:
    HpBar();
    HpBar(int x,int y,Player *player);
    ~HpBar();

    void setVar(int x,int y,Player *player);

    void draw();
    void update();
};