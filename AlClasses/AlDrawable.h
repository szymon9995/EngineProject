#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "AlImage.h"

class AlDrawable
{
public:
    enum Color
    {
        RED,YELLOW,GREEN,BLUE,
        ORANGE,VIOLET,PURPLE,PINK,
        BLACK,WHITE,
        DARK_GREEN,LIME,
        LIGHT_BLUE,DARK_BLUE
    };
private:
    static ALLEGRO_COLOR getColor(Color color);
    static ALLEGRO_COLOR getTransparentColor(Color color, int alpha);
public:

    static void drawImage(AlImage &image,int x,int y);
    static void drawScaledImage(AlImage &image,int x,int y,double scale);

    static void drawFont(AlFont &font,int x,int y,std::string text);

    static void drawTransparentLine(int x,int y,int x2,int y2,int r,int g,int b,int alpha,int thickness);
    static void drawTransparentLine(int x,int y,int x2,int y2,Color color,int alpha,int thickness);
    static void drawLine(int x,int y,int x2,int y2,int r,int g,int b,int thickness);
    static void drawLine(int x,int y,int x2,int y2,Color color,int thickness);
    static void drawTransparentTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b,int alpha,int thickness);
    static void drawTransparentTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color,int alpha,int thickness);
    static void drawTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b,int thickness);
    static void drawTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color,int thickness);
    static void drawTransparentFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b,int alpha);
    static void drawTransparentFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color,int alpha);
    static void drawFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b);
    static void drawFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color);
    static void drawTransparentRectangle(int x,int y,int x2,int y2,int r,int g,int b,int alpha,int thickness);
    static void drawTransparentRectangle(int x,int y,int x2,int y2,Color color,int alpha,int thickness);
    static void drawRectangle(int x,int y,int x2,int y2,int r,int g,int b,int thickness);
    static void drawRectangle(int x,int y,int x2,int y2,Color color,int thickness);
    static void drawTransparentFilledRectangle(int x,int y,int x2,int y2,int r,int g,int b,int alpha);
    static void drawTransparentFilledRectangle(int x,int y,int x2,int y2,Color color,int alpha);
    static void drawFilledRectangle(int x,int y,int x2,int y2,int r,int g,int b);
    static void drawFilledRectangle(int x,int y,int x2,int y2,Color color);
    static void drawTransparentRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b,int alpha,int thickness);
    static void drawTransparentRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color,int alpha,int thickness);
    static void drawRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b,int thickness);
    static void drawRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color,int thickness);
    static void drawTransparentFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b,int alpha);
    static void drawTransparentFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color,int alpha);
    static void drawFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b);
    static void drawFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color);
    static void drawTransparentEllipse(int cx,int cy,int rx,int ry,int r,int g,int b,int alpha,int thickness);
    static void drawTransparentEllipse(int cx,int cy,int rx,int ry,Color color,int alpha,int thickness);
    static void drawEllipse(int cx,int cy,int rx,int ry,int r,int g,int b,int thickness);
    static void drawEllipse(int cx,int cy,int rx,int ry,Color color,int thickness);
    static void drawTransparentFilledEllipse(int cx,int cy,int rx,int ry,int r,int g,int b,int alpha);
    static void drawTransparentFilledEllipse(int cx,int cy,int rx,int ry,Color color,int alpha);
    static void drawFilledEllipse(int cx,int cy,int rx,int ry,int r,int g,int b);
    static void drawFilledEllipse(int cx,int cy,int rx,int ry,Color color);
    static void drawTransparentCircle(int cx,int cy,int rx,int r,int g,int b,int alpha,int thickness);
    static void drawTransparentCircle(int cx,int cy,int rx,Color color,int alpha,int thickness);
    static void drawCircle(int cx,int cy,int r,int g,int b,int thickness);
    static void drawCircle(int cx,int cy,int rx,Color color,int thickness);
    static void drawTransparentFilledCircle(int cx,int cy,int rx,int r,int g,int b,int alpha);
    static void drawTransparentFilledCircle(int cx,int cy,int rx,Color color,int alpha);
    static void drawFilledCircle(int cx,int cy,int rx,int r,int g,int b);
    static void drawFilledCircle(int cx,int cy,int rx,Color color);
};

ALLEGRO_COLOR AlDrawable::getColor(Color color)
{
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
    default: return al_map_rgb(0,0,0); break;
    }
}

ALLEGRO_COLOR AlDrawable::getTransparentColor(Color color, int alpha)
{
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
    default: return al_map_rgba(0,0,0,alpha); break;
    }
}

void AlDrawable::drawTransparentLine(int x,int y,int x2,int y2,int r,int g,int b,int alpha,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_line(x,y,x2,y2,al_map_rgba(rc,gc,bc,alpha),thickness);
}

void AlDrawable::drawTransparentLine(int x,int y,int x2,int y2,Color color,int alpha,int thickness)
{
    al_draw_line(x,y,x2,y2,getTransparentColor(color,alpha),thickness);
}

void AlDrawable::drawLine(int x,int y,int x2,int y2,int r,int g,int b,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_line(x,y,x2,y2,al_map_rgb(rc,gc,bc),thickness);
}

void AlDrawable::drawLine(int x,int y,int x2,int y2,Color color,int thickness)
{
    al_draw_line(x,y,x2,y2,getColor(color),thickness);
}

void AlDrawable::drawTransparentTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b,int alpha,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_triangle(x,y,x2,y2,x3,y3,al_map_rgba(rc,gc,bc,alpha),thickness);
}

void AlDrawable::drawTransparentTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color,int alpha,int thickness)
{
    al_draw_triangle(x,y,x2,y2,x3,y3,getTransparentColor(color,alpha),thickness);
}

void AlDrawable::drawTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_triangle(x,y,x2,y2,x3,y3,al_map_rgb(rc,gc,bc),thickness);
}

void AlDrawable::drawTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color,int thickness)
{
    al_draw_triangle(x,y,x2,y2,x3,y3,getColor(color),thickness);
}

void AlDrawable::drawTransparentFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b,int alpha)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_triangle(x,y,x2,y2,x3,y3,al_map_rgba(rc,gc,bc,alpha));
}

void AlDrawable::drawTransparentFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color,int alpha)
{
    al_draw_filled_triangle(x,y,x2,y2,x3,y3,getTransparentColor(color,alpha));
}

void AlDrawable::drawFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_triangle(x,y,x2,y2,x3,y3,al_map_rgb(rc,gc,bc));
}

void AlDrawable::drawFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color)
{
    al_draw_filled_triangle(x,y,x2,y2,x3,y3,getColor(color));
}

void AlDrawable::drawTransparentRectangle(int x,int y,int x2,int y2,int r,int g,int b,int alpha,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_rectangle(x,y,x2,y2,al_map_rgba(rc,gc,bc,alpha),thickness);
}

void AlDrawable::drawTransparentRectangle(int x,int y,int x2,int y2,Color color,int alpha,int thickness)
{
    al_draw_rectangle(x,y,x2,y2,getTransparentColor(color,alpha),thickness);
}

void AlDrawable::drawRectangle(int x,int y,int x2,int y2,int r,int g,int b,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_rectangle(x,y,x2,y2,al_map_rgb(rc,gc,bc),thickness);
}

void AlDrawable::drawRectangle(int x,int y,int x2,int y2,Color color,int thickness)
{
    al_draw_rectangle(x,y,x2,y2,getColor(color),thickness);
}

void AlDrawable::drawTransparentFilledRectangle(int x,int y,int x2,int y2,int r,int g,int b,int alpha)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_rectangle(x,y,x2,y2,al_map_rgba(rc,gc,bc,alpha));
}

void AlDrawable::drawTransparentFilledRectangle(int x,int y,int x2,int y2,Color color,int alpha)
{
    al_draw_filled_rectangle(x,y,x2,y2,getTransparentColor(color,alpha));
}

void AlDrawable::drawFilledRectangle(int x,int y,int x2,int y2,int r,int g,int b)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_rectangle(x,y,x2,y2,al_map_rgb(rc,gc,bc));
}

void AlDrawable::drawFilledRectangle(int x,int y,int x2,int y2,Color color)
{
    al_draw_filled_rectangle(x,y,x2,y2,getColor(color));
}

void AlDrawable::drawTransparentRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b,int alpha,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_rounded_rectangle(x,y,x2,y2,rx,ry,al_map_rgba(rc,gc,bc,alpha),thickness);
}

void AlDrawable::drawTransparentRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color,int alpha,int thickness)
{
    al_draw_rounded_rectangle(x,y,x2,y2,rx,ry,getTransparentColor(color,alpha),thickness);
}

void AlDrawable::drawRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_rounded_rectangle(x,y,x2,y2,rx,ry,al_map_rgb(rc,gc,bc),thickness);
}

void AlDrawable::drawRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color,int thickness)
{
    al_draw_rounded_rectangle(x,y,x2,y2,rx,ry,getColor(color),thickness);
}

void AlDrawable::drawTransparentFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b,int alpha)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_rounded_rectangle(x,y,x2,y2,rx,ry,al_map_rgba(rc,gc,bc,alpha));
}

void AlDrawable::drawTransparentFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color,int alpha)
{
    al_draw_filled_rounded_rectangle(x,y,x2,y2,rx,ry,getTransparentColor(color,alpha));
}

void AlDrawable::drawFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_rounded_rectangle(x,y,x2,y2,rx,ry,al_map_rgb(rc,gc,bc));
}

void AlDrawable::drawFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color)
{
    al_draw_filled_rounded_rectangle(x,y,x2,y2,rx,ry,getColor(color));
}

void AlDrawable::drawTransparentEllipse(int cx,int cy,int rx,int ry,int r,int g,int b,int alpha,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_ellipse(cx,cy,rx,ry,al_map_rgba(rc,gc,bc,alpha),thickness);
}

void AlDrawable::drawTransparentEllipse(int cx,int cy,int rx,int ry,Color color,int alpha,int thickness)
{
    al_draw_ellipse(cx,cy,rx,ry,getTransparentColor(color,alpha),thickness);
}

void AlDrawable::drawEllipse(int cx,int cy,int rx,int ry,int r,int g,int b,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_ellipse(cx,cy,rx,ry,al_map_rgb(rc,gc,bc),thickness);
}

void AlDrawable::drawEllipse(int cx,int cy,int rx,int ry,Color color,int thickness)
{
    al_draw_ellipse(cx,cy,rx,ry,getColor(color),thickness);
}

void AlDrawable::drawTransparentFilledEllipse(int cx,int cy,int rx,int ry,int r,int g,int b,int alpha)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_ellipse(cx,cy,rx,ry,al_map_rgba(rc,gc,bc,alpha));
}

void AlDrawable::drawTransparentFilledEllipse(int cx,int cy,int rx,int ry,Color color,int alpha)
{
    al_draw_filled_ellipse(cx,cy,rx,ry,getTransparentColor(color,alpha));
}

void AlDrawable::drawFilledEllipse(int cx,int cy,int rx,int ry,int r,int g,int b)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_ellipse(cx,cy,rx,ry,al_map_rgb(rc,gc,bc));
}

void AlDrawable::drawFilledEllipse(int cx,int cy,int rx,int ry,Color color)
{
    al_draw_filled_ellipse(cx,cy,rx,ry,getColor(color));
}

void AlDrawable::drawTransparentCircle(int cx,int cy,int rx,int r,int g,int b,int alpha,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_circle(cx,cy,rx,al_map_rgba(rc,gc,bc,alpha),thickness);
}

void AlDrawable::drawTransparentCircle(int cx,int cy,int rx,Color color,int alpha,int thickness)
{
    al_draw_circle(cx,cy,rx,getTransparentColor(color,alpha),thickness);
}

void AlDrawable::drawCircle(int cx,int cy,int r,int g,int b,int thickness)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_circle(cx,cy,r,al_map_rgb(rc,gc,bc),thickness);
}

void AlDrawable::drawCircle(int cx,int cy,int rx,Color color,int thickness)
{
    al_draw_circle(cx,cy,rx,getColor(color),thickness);
}

void AlDrawable::drawTransparentFilledCircle(int cx,int cy,int rx,int r,int g,int b,int alpha)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_circle(cx,cy,rx,al_map_rgba(rc,gc,bc,alpha));
}

void AlDrawable::drawTransparentFilledCircle(int cx,int cy,int rx,Color color,int alpha)
{
    al_draw_filled_circle(cx,cy,rx,getTransparentColor(color,alpha));
}

void AlDrawable::drawFilledCircle(int cx,int cy,int rx,int r,int g,int b)
{
    int rc=r, gc=g, bc=b;
    if(rc<0)
        rc=0;
    if(gc<0)
        gc=0;
    if(bc<0)
        bc=0;
    if(rc>255)
        rc=255;
    if(gc>255)
        gc=255;
    if(bc>255)
        bc=255;
    al_draw_filled_circle(cx,cy,rx,al_map_rgb(rc,gc,bc));
}

void AlDrawable::drawFilledCircle(int cx,int cy,int rx,Color color)
{
    al_draw_filled_circle(cx,cy,rx,getColor(color));
}

void AlDrawable::drawImage(AlImage &image, int x, int y)
{
    al_draw_bitmap(image.GetBitmap(),x,y,0);
}

void AlDrawable::drawScaledImage(AlImage &image,int x,int y,double scale)
{
    float bitmat_width = al_get_bitmap_width(image.GetBitmap());
    float bitmat_height = al_get_bitmap_height(image.GetBitmap());
    al_draw_scaled_bitmap(image.GetBitmap(),0,0,bitmat_width,bitmat_height,x,y,bitmat_width*scale,bitmat_height*scale,0);
}
