#include <iostream>
#include <allegro5/allegro.h>

using namespace std;

int main()
{
    ALLEGRO_DISPLAY *display;
    //test
    //test
    //test

    if(!al_init())
    {
        std::cout<<"Error could not init allgero5\n";

    }

    display = al_create_display(800,600);

    al_rest(6.0f);

    al_destroy_display(display);
    return 0;
}
