#pragma once
#include "Tile.h"

class CastleDirtTile : public Tile
{
private:
   
public:
    CastleDirtTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};;
    ~CastleDirtTile(){};

    void draw()
    {
        tileImages.getCastleDirtTile().drawScaledImage(x,y,w,h);
    }
};