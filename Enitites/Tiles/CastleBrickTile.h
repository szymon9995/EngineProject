#pragma once
#include "Tile.h"

class CastleBrickTile : public Tile
{
private:
    
public:
    CastleBrickTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};;
    ~CastleBrickTile(){};

    void draw()
    {
        tileImages.getCastleBrickTile().drawScaledImage(x,y,w,h);
    }
};