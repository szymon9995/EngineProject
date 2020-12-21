#pragma once

#include "Tile.h"

class MiddleSkyTile : public Tile
{
private:
    
public:
    MiddleSkyTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~MiddleSkyTile(){};

    void draw()
    {
        tileImages.getMiddleSky().drawScaledImage(x,y,w,h);
    }
    void update()
    {
        
    }
};