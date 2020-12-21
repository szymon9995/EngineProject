#include "Tile.h"

#include "GrassTile.h"
#include "RDSkyTile.h"
#include "RUSkyTile.h"
#include "LDSkyTile.h"
#include "LUSkyTile.h"
#include "MiddleSkyTile.h"
#include "SkyTile.h"
#include "GrassRTile.h"
#include "GrassLTile.h"
#include "DirtLTile.h"
#include "DirtRTile.h"
#include "DirtTile.h"
#include "CastleBrickTile.h"
#include "CastleDirtTile.h"
#include "BackBrickLTile.h"
#include "BackBrickRTile.h"
#include "BackBrickTile.h"

TilesImages Tile::tileImages = TilesImages();

Tile::Tile(int x,int y,int w,int h,Player *player)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->player=player;
}

Tile::~Tile()
{

}

void Tile::update()
{
    FloatRect tileRec(x,y,w,h);
    if(player->pos->Intersect(tileRec))
    {
        if(player->pos->Bottom >= tileRec.Top && player->prev_pos->Bottom <= tileRec.Top)
        {
            player->y = tileRec.Top-h;
            player->DeactiveGravity();
        }
        else if(player->pos->Top <= tileRec.Bottom && player->prev_pos->Top >= tileRec.Bottom)
        {
            player->y = tileRec.Bottom;
        }
        else if(player->pos->Right >= tileRec.Left && player->prev_pos->Right <= tileRec.Left)
        {
            player->x = tileRec.Left-w;
        }
        else if(player->pos->Left <= tileRec.Right && player->prev_pos->Left >=tileRec.Right)
        {
            player->x=tileRec.Right;
        }
    }

}

void Tile::draw()
{
    AlDrawable::drawFilledRectangle(x,y,x+w,y+h,LIME);
}


Tile* Tile::getTile(int x,int y,int w,int h,Player *player,int id)
{
    switch (id)
    {
    case 1:
        return new GrassTile(x,y,w,h,player);
        break;

    case 2:
        return new LUSkyTile(x,y,w,h,player);
        break;

    case 3:
        return new LDSkyTile(x,y,w,h,player);
        break;

    case 4:
        return new RUSkyTile(x,y,w,h,player);
        break;

    case 5:
        return new RDSkyTile(x,y,w,h,player);
        break;

    case 6:
        return new MiddleSkyTile(x,y,w,h,player);
        break;

    case 7:
        return new SkyTile(x,y,w,h,player);
        break;

    case 8:
        return new GrassLTile(x,y,w,h,player);
        break;

    case 9:
        return new GrassRTile(x,y,w,h,player);
        break;

    case 10:
        return new DirtLTile(x,y,w,h,player);
        break;

    case 11:
        return new DirtTile(x,y,w,h,player);
        break;

    case 12:
        return new DirtRTile(x,y,w,h,player);
        break;

    case 13:
        return new CastleBrickTile(x,y,w,h,player);
        break;

    case 14:
        return new CastleDirtTile(x,y,w,h,player);
        break;

    case 15:
        return new BackBrickLTile(x,y,w,h,player);
        break;

    case 16:
        return new BackBrickRTile(x,y,w,h,player);
        break;

    case 17:
        return new BackBrickTile(x,y,w,h,player);
        break;


    default:
        return new Tile(x,y,w,h,player);
        break;
    }
}

void Tile::initTiles()
{
    tileImages.LoadData();
}
