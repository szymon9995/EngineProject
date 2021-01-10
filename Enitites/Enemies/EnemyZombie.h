#pragma once

#include "../../AlAbstract/Entity.h"
#include "../../Type/FloatRect.h"
#include "../../AlClasses/AlDrawable.h"
#include "../../AlClasses/AlImage.h"
#include "../Player/Player.h"

class EnemyZombie : public Entity //klasa wroga zombie
{
private:
    int x,y;//wsporzedne przeciwnika
    int x1,x2;//prawe i lewe wspolrzedne x sciezki
    int w,h;
    bool reverse;//czy idze w druga strone
    AlImage images[4];//zdjecia zombiego
    Player *player;//wskanik na gracza
    int speed;//szybkosc
public:
    EnemyZombie(int x,int y,int x2,int w,int h,Player *player);//konstruktor zombiego, jego wsporzedne i do jakiego x idze oraz wskaznik na gracza
    ~EnemyZombie();//dekonstruktor zombiego

    void draw();//rysowanie zombiego
    void update();//aktualizacja zombiego
};
