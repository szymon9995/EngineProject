#include "Color.h"

#include <allegro5/allegro.h>

static ALLEGRO_COLOR getColor(Color color)
{//Translator koloru na kolor z allegro5
    switch(color) {
    case RED: return al_map_rgb(255,0,0); break;
    case YELLOW: return al_map_rgb(255,255,0); break;
    case GREEN: return al_map_rgb(0,191,0); break;
    case BLUE: return al_map_rgb(0,0,255); break;
    case ORANGE: return al_map_rgb(255,127,0); break;
    case VIOLET: return al_map_rgb(127,31,255); break;
    case PURPLE: return al_map_rgb(127,0,127); break;
    case PINK: return al_map_rgb(255,0,255); break;
    case BLACK: return al_map_rgb(0,0,0); break;
    case WHITE: return al_map_rgb(255,255,255); break;
    case DARK_GREEN: return al_map_rgb(0,127,0); break;
    case LIME: return al_map_rgb(0,255,0); break;
    case LIGHT_BLUE: return al_map_rgb(0,255,255); break;
    case DARK_BLUE: return al_map_rgb(0,0,127); break;
    case GREY: return al_map_rgb(128,128,128); break;
    default: return al_map_rgb(0,0,0); break;
    }
}

static ALLEGRO_COLOR getTransparentColor(Color color, int alpha)
{ //Translator koloru na kolorz z alpha allegro5
    switch(color) {
    case RED: return al_map_rgba(255,0,0,alpha); break;
    case YELLOW: return al_map_rgba(255,255,0,alpha); break;
    case GREEN: return al_map_rgba(0,191,0,alpha); break;
    case BLUE: return al_map_rgba(0,0,255,alpha); break;
    case ORANGE: return al_map_rgba(255,127,0,alpha); break;
    case VIOLET: return al_map_rgba(127,31,255,alpha); break;
    case PURPLE: return al_map_rgba(127,0,127,alpha); break;
    case PINK: return al_map_rgba(255,0,255,alpha); break;
    case BLACK: return al_map_rgba(0,0,0,alpha); break;
    case WHITE: return al_map_rgba(255,255,255,alpha); break;
    case DARK_GREEN: return al_map_rgba(0,127,0,alpha); break;
    case LIME: return al_map_rgba(0,255,0,alpha); break;
    case LIGHT_BLUE: return al_map_rgba(0,255,255,alpha); break;
    case DARK_BLUE: return al_map_rgba(0,0,127,alpha); break;
    case GREY: return al_map_rgba(128,128,128,alpha); break;
    default: return al_map_rgba(0,0,0,alpha); break;
    }
}