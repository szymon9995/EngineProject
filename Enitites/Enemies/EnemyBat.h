#pragma once

#include "../../AlAbstract/Entity.h"
#include "../Player/Player.h"
#include "../../Type/FloatRect.h"
#include "../../AlClasses/AlDrawable.h"
#include "../../AlClasses/AlImage.h"

class EnemyBat : public Entity//kalsa wroga niepoterz
{
private:
    int x,y;//wpolrzedne przeciwnika
    int w,h;//wymiary przeciwnika
    int j,i;//tyczasowe zmienne do animacji (zmienic pozniej na jakas klase animacji)
    Player *player;//wskaznik na gracza
    int radius;//promien kola w ktorym gracz ma sie znalesc by zaczal za nim isc
    int speed;//szyvkosc
    AlImage images[15];//zdjecia do tego przeciwnika
public:
    EnemyBat(int x,int y,Player *player);//konsturktor nietoperza, dajemy jego wspolrzedne pojawienia i wkaznik na gracza
    ~EnemyBat();//dekonstruktor nietoperza

    void draw();//rysowane nietoperza
    void update();//uaktualnianie nietoperza
};
