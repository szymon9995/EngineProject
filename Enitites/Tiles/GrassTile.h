#pragma once
#include "Tile.h"

class GrassTile : public Tile
{
private:
public:
    GrassTile(int x,int y,int w,int h,Player *player) : Tile(x,y,w,h,player) {};
    ~GrassTile();
    void draw();
};