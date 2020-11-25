#pragma once
#include "../AlAbstract/Entity.h"
#include "../AlClasses/AlDrawable.h"
#include "../AlClasses/AlFont.h"
#include "../AlClasses/AlMouse.h"
#include "../AlClasses/AlKeyboard.h"
#include "../AlClasses/AlImage.h"

#include <stdio.h>

class Test2 : public Entity//klada uzywana do testowanaia poprawnosci niektorych zapimplementowanyc rzeczy
{
private:
    int x;
    int y;
    AlFont font;
    AlFont font2;
    AlImage image;
    AlImage image2;
    AlImage image3;
    AlImage images[4];
    bool test;

public:
    Test2();
    ~Test2();
    void draw();
    void update();
};

Test2::Test2()
{
    x=50;
    y=50;
    image.loadImage("images/test.png");
    image2 = AlImage::cropOut(image,50,50,50,50);
    image3 = image.cropOut(0,50,50,50);
    image.loadImage("images/test.png");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            images[i+j] = AlImage::cropOut(image,i*100,j*100,100,100);
    font.LoadDefaultFont();
    font2.LoadFont("fonts/comic.ttf",20,0);
 
}

Test2::~Test2()
{

}

void Test2::draw()
{
    AlDrawable::drawText(font,RED,300,300,"Test2");
    font.drawText(YELLOW,300,320,"Test3");
    font.drawText(YELLOW,300,340,"x:%d y:%d",5,511);
    font2.drawText(GREEN,300,370,"Teeext");
    //if(test)
       // al_draw_text(font.GetFont(),al_map_rgb(255,255,0),400,400,ALLEGRO_ALIGN_CENTER,"Test111");
    AlDrawable::drawImage(image,30,30);
    //image.drawImage(30,400);
    image2.drawImage(230,30);
    //AlDrawable::drawImage(image2,200,30);
    //AlDrawable::drawImage(image3,400,30);
    image3.drawImage(430,30);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            AlDrawable::drawImage(images[i+j],400+(i*101),400+(j*101));
}

void Test2::update()
{

}
