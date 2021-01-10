#pragma once
#include "Tile.h"

class DoorTile : public Tile
{
private:
    bool nextLevel;
public:
    DoorTile(int x,int y,int w,int h,Player *player,Camera *camera) : Tile(x,y,w,h,0,player,camera) {nextLevel=false;};
    ~DoorTile(){};

    void update()
    {
        FloatRect tileRec(x,y,w,h);
        if(player->pos->Intersect(tileRec))
        {
            nextLevel=true;
        }
        if(camera->canDraw(x,y,w,h))
            canDraw=true;
        else
            canDraw=false;
    }

    void draw()
    {
        if(canDraw)
        tileImages->getDoorTile().drawScaledImage(x,y,w,h);
    }

    bool isNextLevel()
    {
        return nextLevel;
    }

    void reloadDoor()
    {
        nextLevel=false;
    }
};
