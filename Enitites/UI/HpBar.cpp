#include "HpBar.h"

HpBar::HpBar()
{

}

HpBar::HpBar(int x,int y,Player *player)
{
    this->x=x;
    this->y=y;
    w=200;
    h=80;
    font.LoadFont("fonts/comic.ttf",14,0);
    this->player=player;
}

HpBar::~HpBar()
{

}

void HpBar::setVar(int x,int y,Player *player)
{
    this->x=x;
    this->y=y;
    w=200;
    h=80;
    font.LoadFont("fonts/comic.ttf",14,0);
    this->player=player;
}

void HpBar::draw()
{
    AlDrawable::drawFilledRectangle(x,y,w,h,PINK);
    AlDrawable::drawFilledRectangle(x,y,w -((3-player->getHp())* w/3 ),h,RED);
    font.drawText(YELLOW,(x+w)/2,-12+(y+h)/2,"HP : %d",player->getHp());
}

void HpBar::update()
{

}
