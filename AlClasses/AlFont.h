#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <iostream>

class AlFont
{
private:
    ALLEGRO_FONT *font;
public:
    ALLEGRO_FONT* GetFont();

    
    //do swojego wlasnego pliku dac poziej
    //void drawTextf();
    void DrawText(ALLEGRO_COLOR color,int x,int y,int flags,std::string text);

    AlFont();
    AlFont(std::string path,int size,int flags);
    AlFont(std::string path,int size,int flags,bool &check);
    ~AlFont();
};

ALLEGRO_FONT* AlFont::GetFont()
{
    return font;
}

void AlFont::DrawText(ALLEGRO_COLOR color,int x,int y,int flags,std::string text)
{
    al_draw_text(font,color,x,y,flags,text.c_str());
}

AlFont::AlFont(std::string path,int size,int flags)
{
    font = al_load_font(path.c_str(),size,flags);
    if(font==NULL)
    {
        font = al_create_builtin_font();
    }
}

AlFont::AlFont(std::string path,int size,int flags,bool &check)
{
    font = al_load_font(path.c_str(),size,flags);
    if(font==NULL)
    {
        font = al_create_builtin_font();
        check=false;
    }
    else check=true;
}

AlFont::AlFont()
{
    font = al_create_builtin_font();
}

AlFont::~AlFont()
{
    al_destroy_font(font);
}
