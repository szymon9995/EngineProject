#pragma once

#include "../../AlAbstract/Entity.h"
#include "../../AlClasses/AlKeyboard.h"
#include "../../AlClasses/AlDrawable.h"
#include "../../AlClasses/AlFont.h"
#include "../../AlClasses/AlImage.h"
#include "../../Type/FloatRect.h"

#include "../../AlClasses/AlTimer.h"
#include "../../Engine/MainQueu.h"

enum DIRECTION{
    UP,DOWN,LEFT,RIGHT
};

class Player : public Entity //klasa gracza, glowny do sterowania
{
    private:
        
        int atk, hp; 
        double max_spd, jump;
        AlFont font;
        bool invincible;

        const double gravity = 0.2;
        bool activate_gravity;
        bool isAttack;
        bool isCoolDown;
       
        AlTimer attackTimer = AlTimer(0.5);
        AlTimer attackCoolDown = AlTimer(0.1);
        AlTimer invincibleTimer = AlTimer(3.0);
        void Jump();
        void Invincibility();
        void AttackCoolDown();
        void Attack();

        AlImage playerImage;
    public:
        int x,y;
        int xp,yp;
        int w,h;
        FloatRect *pos,*prev_pos,*attackBox;
        DIRECTION dir,lastdir;
        
        
        Player();
        ~Player();
        void update();//aktualizacja gracza
        void draw();//rysowanie gracza
        void LoadPlayer(int x, int y, int w, int h);//ladowanie gracza(jego wsporzenych itp)
        void OnHit(int hpDamage);//funckja (wywolywana przez inny Entity(przeciwnikow)) 
        void OnHitIgnoreInvic(int hpDamage);
        void DeactiveGravity();//deaktywacja grawitacji
        void ActiveGravity();
        int getHp();//dostanie zycia
        bool isAttacking();
};