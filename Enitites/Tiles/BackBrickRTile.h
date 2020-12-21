#pragma once
#include "Tile.h"

class BackBrickRTile : public Tile
{
private:
    
public:
    BackBrickRTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};;
    ~BackBrickRTile(){};

    void draw()
    {
        tileImages.getBackBrickRTile().drawScaledImage(x,y,w,h);
    }
    void update()
    {
        
    }
};
