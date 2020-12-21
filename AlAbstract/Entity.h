#pragma once

class Entity
{
    protected:
    bool isAlive = true;
public:
    virtual ~Entity() {};//wirtualny dekonstruktor klasy Entity
    virtual void draw() {};//wirtualna metoda sluzaca do rysowania
    virtual void update() {};//wirtualna metoda sluzaca do aktualizacji danych
};