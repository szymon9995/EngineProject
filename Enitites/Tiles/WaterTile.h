#pragma once

#include "Tile.h"

class WaterTile : public Tile
{
private:
   
public:
    WaterTile(int x,int y,int w,int h,int tileID,Player *player,Camera *camera) : Tile(x,y,w,h,tileID,player,camera) {};
    ~WaterTile(){};

    void update(){
        FloatRect tileRec(x,y,w,h);
        if(player->pos->Intersect(tileRec))
        {
            player->OnHitIgnoreInvic(3);
        }
        if(camera->canDraw(x,y,w,h))
            canDraw=true;
        else
            canDraw=false;
     };
};
