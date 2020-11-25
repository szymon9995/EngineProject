#pragma once

typedef struct ALLEGRO_DISPLAY ALLEGRO_DISPLAY;
typedef struct ALLEGRO_EVENT_SOURCE ALLEGRO_EVENT_SOURCE;

class AlDisplay//klasa do przetrzymywania ekranu 
{
private:    
    ALLEGRO_DISPLAY *display;
    int flags;
public:

    AlDisplay();//komstruktor ekranu
    ~AlDisplay();//dekonstruktor ekranu

    void CreateDisplay(int w,int h);//ustawienie rozmiarow ekranu 
    void SetWindowMode(bool isFullScreen,bool isResizable);//ustawienie czy ekran ma byc pelnoekranowy i byc rozszezany
    int getDisplayWidth();//dostanie szerokosci ekranu
    int getDisplayHeight();//dostanie wysokosci ekranu
    ALLEGRO_EVENT_SOURCE* DisplayEvent();//dotsnie zrodla wydarzenia ekranu

};