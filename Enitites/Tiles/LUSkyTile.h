#pragma once

#include "Tile.h"

class LUSkyTile : public Tile
{
private:
    
public:
    LUSkyTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~LUSkyTile(){};
    void draw()
    {
        tileImages.getLUSky().drawScaledImage(x,y,w,h);
    }
    void update()
    {
        
    }
};