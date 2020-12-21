#pragma once
#include <stdarg.h>
#include "Color.h"
#include <iostream>

typedef class AlImage AlImage;
typedef class AlFont AlFont;

class AlDrawable//klasa majaca rozne funckje do rysowania
{
public:

    static void drawImage(AlImage &image,int x,int y);//rysowanie załadowanego zdjecia
    static void drawScaledImage(AlImage &image,int x,int y,double scale);//rysowanie załadowanego zdjecia w podanej skali
    static void drawScaledImage(AlImage &image,int x,int y,int w,int h);

    static void drawText(AlFont &font,Color color,int alpha,int x,int y,std::string text,...);//rsowanie teksu za pomoca fonta na podanych sporzenych i kolorze
    static void drawText(AlFont &font,Color color,int x,int y,std::string text,...);//rsowanie teksu za pomoca fonta na podanych sporzenych i kolorze
    static void drawText(AlFont &font,int r,int g,int b,int alpha,int x,int y,std::string text,...);//rsowanie teksu za pomoca fonta na podanych sporzenych i kolorze
    static void drawText(AlFont &font,int r,int g,int b,int x,int y,std::string text,...);//rsowanie teksu za pomoca fonta na podanych sporzenych i kolorze

    static void drawTransparentLine(int x,int y,int x2,int y2,int r,int g,int b,int alpha,int thickness);//rysowanie lini z alpha
    static void drawTransparentLine(int x,int y,int x2,int y2,Color color,int alpha,int thickness);//rysowanie lini z alpha
    static void drawLine(int x,int y,int x2,int y2,int r,int g,int b,int thickness);//rysowanie lini
    static void drawLine(int x,int y,int x2,int y2,Color color,int thickness);//rysowanie lini
    static void drawTransparentTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b,int alpha,int thickness);//rysowanie trojkatu z alpha
    static void drawTransparentTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color,int alpha,int thickness);//rysowanie trojkatu z alpha
    static void drawTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b,int thickness);//rysowanie trojkatu
    static void drawTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color,int thickness);//rysowanie trojkatu
    static void drawTransparentFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b,int alpha);//rysowanie wypelnionego trojkatu z alpha
    static void drawTransparentFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color,int alpha);//rysowanie wypelnionego trojkatu z alpha
    static void drawFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,int r,int g,int b);//rysowanie wypelnionego trojkatu
    static void drawFilledTriangle(int x,int y,int x2,int y2,int x3,int y3,Color color);//rysowanie wypelnionego trojkatu
    static void drawTransparentRectangle(int x,int y,int x2,int y2,int r,int g,int b,int alpha,int thickness);//rysowanie kwadratu z alpha
    static void drawTransparentRectangle(int x,int y,int x2,int y2,Color color,int alpha,int thickness);;//rysowanie kwadratu z alpha
    static void drawRectangle(int x,int y,int x2,int y2,int r,int g,int b,int thickness);;//rysowanie kwadratu
    static void drawRectangle(int x,int y,int x2,int y2,Color color,int thickness);;//rysowanie kwadratu
    static void drawTransparentFilledRectangle(int x,int y,int x2,int y2,int r,int g,int b,int alpha);;//rysowanie wypelnionego kwadratu z alpha
    static void drawTransparentFilledRectangle(int x,int y,int x2,int y2,Color color,int alpha);//rysowanie wypelnionego kwadratu z alpha
    static void drawFilledRectangle(int x,int y,int x2,int y2,int r,int g,int b);//rysowanie wypelnionego kwadratu
    static void drawFilledRectangle(int x,int y,int x2,int y2,Color color);//rysowanie wypelnionego kwadratu
    static void drawTransparentRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b,int alpha,int thickness);//rysowanie zaokraglonego kwadratu z alpha
    static void drawTransparentRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color,int alpha,int thickness);//rysowanie zaokraglonego kwadratu z alpha
    static void drawRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b,int thickness);//rysowanie zaokraglonego kwadratu
    static void drawRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color,int thickness);//rysowanie zaokraglonego kwadratu
    static void drawTransparentFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b,int alpha);//rysowanie zaokraglonego wypelnionego kwadratu z alpha
    static void drawTransparentFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color,int alpha);//rysowanie zaokraglonego wypelnionego kwadratu z alpha
    static void drawFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,int r,int g,int b);//rysowanie zaokraglonego wypelnionego kwadratu
    static void drawFilledRoundedRectangle(int x,int y,int x2,int y2,int rx,int ry,Color color);//rysowanie zaokraglonego wypelnionego kwadratu
    static void drawTransparentEllipse(int cx,int cy,int rx,int ry,int r,int g,int b,int alpha,int thickness);//rysowamoe eklipsy z alpha
    static void drawTransparentEllipse(int cx,int cy,int rx,int ry,Color color,int alpha,int thickness);//rysowamoe eklipsy z alpha
    static void drawEllipse(int cx,int cy,int rx,int ry,int r,int g,int b,int thickness);//rysowamoe eklipsy
    static void drawEllipse(int cx,int cy,int rx,int ry,Color color,int thickness);//rysowamoe eklipsy
    static void drawTransparentFilledEllipse(int cx,int cy,int rx,int ry,int r,int g,int b,int alpha);//rysowamoe wypelnionej eklipsy z alpha
    static void drawTransparentFilledEllipse(int cx,int cy,int rx,int ry,Color color,int alpha);//rysowamoe wypelnionej eklipsy z alpha
    static void drawFilledEllipse(int cx,int cy,int rx,int ry,int r,int g,int b);//rysowamoe wypelnionej eklipsy
    static void drawFilledEllipse(int cx,int cy,int rx,int ry,Color color);//rysowamoe wypelnionej eklipsy
    static void drawTransparentCircle(int cx,int cy,int rx,int r,int g,int b,int alpha,int thickness);//rysowanie kola z alpha
    static void drawTransparentCircle(int cx,int cy,int rx,Color color,int alpha,int thickness);//rysowanie kola z alpha
    static void drawCircle(int cx,int cy,int r,int g,int b,int thickness);//rysowanie kola
    static void drawCircle(int cx,int cy,int rx,Color color,int thickness);//rysowanie kola
    static void drawTransparentFilledCircle(int cx,int cy,int rx,int r,int g,int b,int alpha);//rysowanie wypelnionego kola z alpha
    static void drawTransparentFilledCircle(int cx,int cy,int rx,Color color,int alpha);//rysowanie wypelnionego kola z alpha
    static void drawFilledCircle(int cx,int cy,int rx,int r,int g,int b);//rysowanie wypelnionego kola
    static void drawFilledCircle(int cx,int cy,int rx,Color color);//rysowanie wypelnionego kola
};