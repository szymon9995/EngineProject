#include "AlDrawable.h"

#include "Color.cpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "AlImage.h"
#include "AlFont.h"

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
    if(image.GetBitmap()!=NULL)
    al_draw_bitmap(image.GetBitmap(),x,y,0);
}

void AlDrawable::drawScaledImage(AlImage &image,int x,int y,double scale)
{
    if(image.GetBitmap()!=NULL)
    {
        int bitmat_width = image.getWidth();
        int bitmat_height = image.getHeight();
        al_draw_scaled_bitmap(image.GetBitmap(),0,0,bitmat_width,bitmat_height,x,y,bitmat_width*scale,bitmat_height*scale,0);
    }
    
}

void AlDrawable::drawText(AlFont &font,Color color,int alpha,int x,int y,std::string text,...)
{
    if(font.GetFont()==NULL)
        return;
    va_list va_l;
    va_start(va_l,text);
    char tex[text.length()+100];
    vsprintf(tex,text.c_str(),va_l);
    al_draw_text(font.GetFont(),getTransparentColor(color,alpha),x,y,ALLEGRO_ALIGN_CENTER,tex);

    va_end(va_l);
}

void AlDrawable::drawText(AlFont &font,Color color,int x,int y,std::string text,...)
{
    if(font.GetFont()==NULL)
        return;
    va_list va_l;
    va_start(va_l,text);
    char tex[text.length()+100];
    vsprintf(tex,text.c_str(),va_l);
    al_draw_text(font.GetFont(),getColor(color),x,y,ALLEGRO_ALIGN_CENTER,tex);

    va_end(va_l);
}

void AlDrawable::drawText(AlFont &font,int r,int g,int b,int alpha,int x,int y,std::string text,...)
{
    if(font.GetFont()==NULL)
        return;
    va_list va_l;
    va_start(va_l,text);
    char tex[text.length()+100];
    vsprintf(tex,text.c_str(),va_l);
    al_draw_text(font.GetFont(),al_map_rgba(r,g,b,alpha),x,y,ALLEGRO_ALIGN_CENTER,tex);
    va_end(va_l);
}

void AlDrawable::drawText(AlFont &font,int r,int g,int b,int x,int y,std::string text,...)
{
    if(font.GetFont()==NULL)
        return;
    va_list va_l;
    va_start(va_l,text);
    char tex[text.length()+100];
    vsprintf(tex,text.c_str(),va_l);
    al_draw_text(font.GetFont(),al_map_rgb(r,g,b),x,y,ALLEGRO_ALIGN_CENTER,tex);
    va_end(va_l);
}