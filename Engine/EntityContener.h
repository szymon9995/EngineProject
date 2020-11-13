#pragma once

#include "../AlAbstract/Entity.h"
#include <list>

class EntityContener
{
private:
    std::list<Entity *> content;
public:
    EntityContener();
    ~EntityContener();

    void Update();
    void Draw();
    void Register(Entity* entity);

    
};

EntityContener::EntityContener()
{
}

EntityContener::~EntityContener()
{
}

void EntityContener::Update()
{
    for (std::list<Entity *>::iterator it=content.begin(); it != content.end(); ++it)
    {
        Entity* tmp = *it;
        tmp->update();
    }
}

void EntityContener::Draw()
{
    for (std::list<Entity *>::iterator it=content.begin(); it != content.end(); ++it)
    {
        Entity* tmp = *it;
        tmp->draw();
    }
}

void EntityContener::Register(Entity *entity)
{
    content.push_back(entity);
}
