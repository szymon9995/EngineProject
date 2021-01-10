#include "Tile.h"

#include "BackRoundTile.h"
#include "WaterTile.h"
#include "../../Engine/StartUpConfig.h"

TilesImages *Tile::tileImages = new TilesImages();

Tile::Tile(int x,int y,int w,int h,int tileID,Player *player,Camera *camera)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->player=player;
    this->tileID=tileID;
    this->camera=camera;
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
    if(camera->canDraw(x,y,w,h))
        canDraw=true;
    else
        canDraw=false;
}

void Tile::draw()
{
    
    if(canDraw)
    tileImages->getTileImage(tileID).drawScaledImage(x,y,w,h);
    //AlDrawable::drawFilledRectangle(x,y,x+w,y+h,LIME);
}


Tile* Tile::getTile(int x,int y,int w,int h,Player *player,Camera *camera,int id)
{
    switch (id)
    {

    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 15:
    case 16:
    case 17:
        return new BackRoundTile(x,y,w,h,id,player,camera);
        break;

    case 1:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    default:
        return new Tile(x,y,w,h,id,player,camera);
        break;
    case 18:
        return new WaterTile(x,y,w,h,id,player,camera);
        break;
    }
}

void Tile::initTiles()
{
    tileImages->LoadData();
}

void Tile::destroyTiles()
{
    delete tileImages;
    tileImages=NULL;
}