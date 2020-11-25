#pragma once

#include "../../AlAbstract/Entity.h"
#include "../../AlClasses/AlKeyboard.h"
#include "../../AlClasses/AlDrawable.h"
#include "../../AlClasses/AlFont.h"
#include "../../Type/FloatRect.h"

class Player : public Entity //klasa gracza, glowny do sterowania
{
    private:
        
        int atk, hp; 
        double max_spd, jump;
        AlFont font;
        bool invincible;

        const double gravity = 0.2;
        bool activate_gravity;

        void Jump();

    public:
        int x,y;
        int xp,yp;
        int w,h;
        FloatRect *pos,*prev_pos;

        Player();
        ~Player();
        void update();//aktualizacja gracza
        void draw();//rysowanie gracza
        void LoadPlayer(int x, int y, int w, int h);//ladowanie gracza(jego wsporzenych itp)
        void OnHit();//funckja (wywolywana przez inny Entity(przeciwnikow)) 
        void DeactiveGravity();//deaktywacja grawitacji
        int getHp();//dostanie zycia
};