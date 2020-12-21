#pragma once
#include "Tile.h"

class DirtTile : public Tile
{
private:
   
public:
    DirtTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~DirtTile(){};

    void draw()
    {
        tileImages.getDirtTile().drawScaledImage(x,y,w,h);
    }
};
