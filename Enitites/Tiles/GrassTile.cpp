#include "GrassTile.h"

GrassTile::~GrassTile()
{

}

void GrassTile::draw()
{
   tileImages.getGrassTile().drawScaledImage(x,y,w,h);
}