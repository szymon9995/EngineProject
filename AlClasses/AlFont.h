#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <stdarg.h>

#include "Color.h"

class AlFont//klasa przetrzymujaca czcionke
{
private:
    ALLEGRO_FONT *font;
public:
    ALLEGRO_FONT* GetFont();

    AlFont();//konstruktor fonta
    ~AlFont();//destruktor fonta

    void LoadDefaultFont();//ladowanie podtawowego fonta
    bool LoadFont(std::string path,int size,int flags);//ladowanie fonta z okreslonej sciezki o okreslonym rozmiarze

    void drawText(Color color,int alpha,int x,int y,std::string text,...);//pisanie tekstu na ekranie o podanym kolorze i wspolrzednych,przeciazana funckja dla koloru i przezroczystosci
    void drawText(Color color,int x,int y,std::string text,...);
    void drawText(int r,int g,int b,int alpha,int x,int y,std::string text,...);
    void drawText(int r,int g,int b,int x,int y,std::string text,...);
};
