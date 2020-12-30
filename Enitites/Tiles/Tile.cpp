#include "Tile.h"

#include "BackRoundTile.h"

TilesImages *Tile::tileImages = new TilesImages();

Tile::Tile(int x,int y,int w,int h,int tileID,Player *player)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->player=player;
    this->tileID=tileID;
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
    tileImages->getTileImage(tileID).drawScaledImage(x,y,w,h);
    //AlDrawable::drawFilledRectangle(x,y,x+w,y+h,LIME);
}


Tile* Tile::getTile(int x,int y,int w,int h,Player *player,int id)
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
        return new BackRoundTile(x,y,w,h,id,player);
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
        return new Tile(x,y,w,h,id,player);
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