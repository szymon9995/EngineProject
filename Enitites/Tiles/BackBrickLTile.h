#pragma once
#include "Tile.h"

class BackBrickLTile : public Tile
{
private:
    
public:
    BackBrickLTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};;
    ~BackBrickLTile(){};

    void draw()
    {
        tileImages.getBackBrickLTile().drawScaledImage(x,y,w,h);
    }
    void update()
    {
        
    }
};