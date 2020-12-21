#pragma once
#include "Tile.h"

class BackBrickTile : public Tile
{
private:
    
public:
    BackBrickTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};;
    ~BackBrickTile(){};

    void draw()
    {
        tileImages.getBackBrickTile().drawScaledImage(x,y,w,h);
    }
    void update()
    {
        
    }
};