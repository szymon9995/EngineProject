#pragma once

#include "Tile.h"

class RDSkyTile : public Tile
{
private:
    
public:
    RDSkyTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~RDSkyTile(){};

    void draw()
    {
        tileImages.getRDSky().drawScaledImage(x,y,w,h);
    }

    void update()
    {

    }
};