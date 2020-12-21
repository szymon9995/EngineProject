#pragma once
#include "Tile.h"

class DirtLTile : public Tile
{
private:
    
public:
    DirtLTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~DirtLTile(){};

    void draw()
    {
        tileImages.getDirtLTile().drawScaledImage(x,y,w,h);
    }
};