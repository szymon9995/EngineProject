#pragma once

#include "../AlAbstract/Entity.h"
#include <list>

class EntityContener
{
private:
    std::list<Entity *> content;//przechowywacz wskanizkow na obiekty Entity
public:
    EntityContener();//konstruktor kontenera
    ~EntityContener();//dekonstruktor kontenera

    void Update();//aktualizacja wszysrkich enityty
    void Draw();//rysowanie wszystkich Enitity
    void Register(Entity* entity);//Rejestracja Entity (przez wskaznik)
    void Unload();//odładowywanie obiektow Entity
    
};