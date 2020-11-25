#include "Tile.h"

Tile::Tile(int x,int y,int w,int h,Player *player)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    this->player=player;
    ID = 0;
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

unsigned int Tile::getID()
{
    return ID;
}
