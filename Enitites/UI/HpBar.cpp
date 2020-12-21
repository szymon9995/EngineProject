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
    heart.loadImage("images/HpBar/heart.png");
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
    heart.loadImage("images/HpBar/heart.png");
    this->player=player;
}

void HpBar::draw()
{
    int w=heart.getWidth();
    for(int i=0;i<player->getHp();i++)
        heart.drawImage(x+(i*w),y);
}

void HpBar::update()
{

}
