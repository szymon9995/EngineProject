#pragma once
#include "../AlAbstract/Entity.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


class Test2 : public Entity
{   
private:
    int x;
    int y;
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
    al_draw_filled_rectangle(x,50,x+150,200,al_map_rgb(255,255,0));
}

void Test2::update()
{
    x++;
}