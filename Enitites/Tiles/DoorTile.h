#pragma once
#include "Tile.h"

class DoorTile : public Tile
{
private:
    bool nextLevel;
public:
    DoorTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {nextLevel=false;};
    ~DoorTile(){};

    void update()
    {
        FloatRect tileRec(x,y,w,h);
        if(player->pos->Intersect(tileRec))
        {
            nextLevel=true;
        }
    }

    void draw()
    {
       tileImages.getDoorTile().drawScaledImage(x,y,w,h);
    }

    bool isNextLevel()
    {
        return nextLevel;
    }
};
