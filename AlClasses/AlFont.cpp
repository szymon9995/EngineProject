#include "AlFont.h"

#include "Color.cpp"

ALLEGRO_FONT* AlFont::GetFont()
{
    return font;
}

AlFont::AlFont()
{
    font = NULL;
}

void AlFont::LoadDefaultFont()
{
    if(font!=NULL)
        al_destroy_font(font);
    font =al_create_builtin_font();
}

bool AlFont::LoadFont(std::string path,int size,int flags)
{
    if(font!=NULL)
        al_destroy_font(font);
    font = al_load_font(path.c_str(),size,flags);
    if(font==NULL)
    {
        font = al_create_builtin_font();
        return false;
    }
    return true;
}

AlFont::~AlFont()
{
    if(font!=NULL)
        al_destroy_font(font);
}


void AlFont::drawText(Color color,int alpha,int x,int y,std::string text,...)
{
    if(font==NULL)
        return;
    va_list va_l;
    va_start(va_l,text);
    char tex[text.length()+100];
    vsprintf(tex,text.c_str(),va_l);
    al_draw_text(font,getTransparentColor(color,alpha),x,y,ALLEGRO_ALIGN_CENTER,tex);

    va_end(va_l);
}

void AlFont::drawText(Color color,int x,int y,std::string text,...)
{
    if(font==NULL)
        return;
    va_list va_l;
    va_start(va_l,text);
    char tex[text.length()+100];
    vsprintf(tex,text.c_str(),va_l);
    al_draw_text(font,getColor(color),x,y,ALLEGRO_ALIGN_CENTER,tex);

    va_end(va_l);
}

void AlFont::drawText(int r,int g,int b,int alpha,int x,int y,std::string text,...)
{
    if(font==NULL)
        return;
    va_list va_l;
    va_start(va_l,text);
    char tex[text.length()+100];
    vsprintf(tex,text.c_str(),va_l);
    al_draw_text(font,al_map_rgba(r,g,b,alpha),x,y,ALLEGRO_ALIGN_CENTER,tex);
    va_end(va_l);
}

void AlFont::drawText(int r,int g,int b,int x,int y,std::string text,...)
{
    if(font==NULL)
        return;
    va_list va_l;
    va_start(va_l,text);
    char tex[text.length()+100];
    vsprintf(tex,text.c_str(),va_l);
    al_draw_text(font,al_map_rgb(r,g,b),x,y,ALLEGRO_ALIGN_CENTER,tex);
    va_end(va_l);
}