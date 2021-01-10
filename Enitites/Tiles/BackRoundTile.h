#pragma once
#include "Tile.h"
#include "../../Engine/StartUpConfig.h"
class BackRoundTile : public Tile
{
private:
   
public:
    BackRoundTile(int x,int y,int w,int h,int tileID,Player *player,Camera *camera) : Tile(x,y,w,h,tileID,player,camera) {};
    ~BackRoundTile(){};
    void update(){
    if(camera->canDraw(x,y,w,h))
        canDraw=true;
    else
        canDraw=false;

    };
};