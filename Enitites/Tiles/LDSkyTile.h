#pragma once

#include "Tile.h"

class LDSkyTile : public Tile
{
private:
    
public:
    LDSkyTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~LDSkyTile(){};
    void draw()
    {
        tileImages.getLDSky().drawScaledImage(x,y,w,h);
    }
    void update()
    {
        
    }
};