#include <iostream>
#include <allegro5/allegro.h>
#include "AlClasses/AlInitAll.h"
#include "AlClasses/AlDisplay.h"
#include "AlClasses/AlImage.h"
#include "AlClasses/AlFont.h"

using namespace std;

int main()
{

    //Init allegro,keyboard,mouse,primitives itp i sprawdzenia czy nie ma bledu
    bool test;
    AlInitAll T= AlInitAll(test);
    if(test==false)
    {
        cout<<T.ReturnError()<<endl;
        return -1;
    }

    //robienie display
    AlDisplay display(800,600);

    //robienie image (dodac lepsze postepowanie kiedy nie mozna zaladowac obrazu)
    AlImage image=AlImage("images/test.png");

    //ladowanie fonta automatycznego
    AlFont font = AlFont();
    //oraz comic sans fonta
    AlFont comic_sans_font("fonts/comic.ttf",16,0);

    al_draw_bitmap(image.GetBitmap(),20,20,0);

    al_draw_text(comic_sans_font.GetFont(),al_map_rgb(255,255,0),400,400,ALLEGRO_ALIGN_CENTER,"Test Comic!");

    al_draw_text(font.GetFont(),al_map_rgb(255,255,0),400,500,ALLEGRO_ALIGN_CENTER,"Test Default!");

    al_flip_display();

    al_rest(6.0f);


    return 0;
}
