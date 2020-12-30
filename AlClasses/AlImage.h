#pragma once
#include <iostream>
#include <cstring>
#include <allegro5/allegro.h>

class AlImage//klasa przetrzymujaca bitmapy zdjec
{
private:
    ALLEGRO_BITMAP *bitmap;
    void loadImage(ALLEGRO_BITMAP* image);//konstrukor bitmapy przez podanie innej juz zaladowanej/dostepnej bitmapy
    
public:
    std::string imgname;
    ALLEGRO_BITMAP* GetBitmap();

    AlImage();//kostruktor
    ~AlImage();//destruktor

    bool loadImage(std::string path);//ladowanie zdjecia przez podana sciezke do pliku
    void unLoadImage();//zwalnianie bitmapy
    AlImage& cropOut(int x,int y,int w,int h);//wycinanie kawalka zdjecia i tworzenie z niego nowej instacji klasu AlImage
    static AlImage& cropOut(AlImage& image,int x,int y,int w,int h);//wycinanie kawalka zdjecia i tworzenie z niego nowej instacji klasu AlImage

    int getWidth();//dostanie szerokosci zdjecia
    int getHeight();//dostanie wysokosci zdjecia

    void drawImage(int x, int y);//rysowanie zdjecia na podonych wpolrzednych
    void drawScaledImage(int x,int y,double scale);//rysowanie zdjecia na podanyc wpolrzednych i podanej skali
    void drawScaledImage(int x,int y,int w,int h);
};