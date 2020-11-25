#pragma once

#include "../../AlAbstract/Entity.h"
#include "../Player/Player.h"
#include "../../Type/FloatRect.h"
#include "../../AlClasses/AlDrawable.h"

class Tile : public Entity
{
private:
    unsigned int ID;
    int x,y;
    int w,h;
    Player *player;

public:
    Tile(int x,int y,int w,int h,Player *player);
    ~Tile();

    void draw();
    void update();
    
    unsigned int getID();
};