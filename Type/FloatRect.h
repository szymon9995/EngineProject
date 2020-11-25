#pragma once

class FloatRect//klasa majaca wporzedne rogow kwadratu(uzywana do detekcji kolizji)
{
private:
    
public:
    FloatRect(float x,float y,float w,float h);//konstruktor kwadratu wporzedne i wymiary kwadratu

    FloatRect();
    ~FloatRect();//dekonstruktor

    bool Intersect(FloatRect f);//czy kwadraty na siebie sie nakladaja

    const float Left,Right,Top,Bottom;//rogi kwadratu
};

