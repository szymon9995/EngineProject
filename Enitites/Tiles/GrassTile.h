#pragma once
#include "../../AlAbstract/Entity.h"
#include "../../AlAbstract/Tile.h"

#include "../../AlClasses/AlDrawable.h"


class GrassTile : public Tile
{
private:
public:
    GrassTile(int x,int y,int w,int h,int ID,bool collision);
    ~GrassTile();

    void draw();
    void update();
};

GrassTile::GrassTile(int x,int y,int w,int h,int ID,bool collision)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->ID=ID;
    this->collistion=collistion;
}

GrassTile::~GrassTile()
{

}

void GrassTile::draw()
{
    AlDrawable::drawFilledRectangle(x,y,x+w,y+h,AlDrawable::LIME);
}

void GrassTile::update()
{

}
