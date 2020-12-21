#pragma once

#include "Tile.h"

class RUSkyTile : public Tile
{
private:
    
public:
    RUSkyTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~RUSkyTile(){};

    void draw()
    {
        tileImages.getRUSky().drawScaledImage(x,y,w,h);
    }
    void update()
    {
        
    }
};