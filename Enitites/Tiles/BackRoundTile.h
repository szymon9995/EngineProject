#pragma once
#include "Tile.h"

class BackRoundTile : public Tile
{
private:
   
public:
    BackRoundTile(int x,int y,int w,int h,int tileID,Player *player) : Tile(x,y,w,h,tileID,player) {};
    ~BackRoundTile(){};
    void update(){};
};