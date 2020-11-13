#pragma once
#include "../AlAbstract/Entity.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "../AlClasses/AlDrawable.h"
#include "../AlClasses/AlFont.h"
#include "../AlClasses/AlMouse.h"
#include "../AlClasses/AlKeyboard.h"


class Test2 : public Entity
{   
private:
    int x;
    int y;
    AlFont font;

public:
    ~Test2();
    void draw();
    void update();
};

Test2::~Test2()
{
    x=50;
    y=50;
}

void Test2::draw()
{
    AlDrawable::drawFont(font,AlDrawable::RED,300,300,"Test2");
    al_draw_text(font.GetFont(),al_map_rgb(255,255,0),400,400,ALLEGRO_ALIGN_CENTER,"Test111");
}

void Test2::update()
{
    
}