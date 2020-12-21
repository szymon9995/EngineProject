#pragma once

#include "Tile.h"

class SkyTile : public Tile
{
private:
    
public:
    SkyTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~SkyTile(){};

    void draw()
    {
        tileImages.getSky().drawScaledImage(x,y,w,h);
    }
    void update()
    {
        
    }
};
