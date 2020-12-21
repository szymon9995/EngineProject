#pragma once
#include "Tile.h"

class DirtRTile : public Tile
{
private:
    
public:
    DirtRTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~DirtRTile(){};

    void draw()
    {
        tileImages.getDirtRTile().drawScaledImage(x,y,w,h);
    }
};