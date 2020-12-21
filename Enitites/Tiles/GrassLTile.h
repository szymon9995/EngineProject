#pragma once
#include "Tile.h"

class GrassLTile : public Tile
{
private:
    
public:
    GrassLTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~GrassLTile(){};

    void draw()
    {
        tileImages.getGrassLTile().drawScaledImage(x,y,w,h);
    }
};