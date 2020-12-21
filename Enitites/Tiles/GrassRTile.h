#pragma once
#include "Tile.h"

class GrassRTile : public Tile
{
private:
    
public:
    GrassRTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~GrassRTile(){};

    void draw()
    {
        tileImages.getGrassRTile().drawScaledImage(x,y,w,h);
    }
};
