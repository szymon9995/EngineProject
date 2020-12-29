#include "EntityContener.h"

EntityContener::EntityContener()
{
}

EntityContener::~EntityContener()
{
    Unload();
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

void EntityContener::Unload()
{
    while(!content.empty())
    {
        delete content.back();
        content.pop_back();
    }
        
}

void EntityContener::ResurectAllEntities()
{
    for (std::list<Entity *>::iterator it=content.begin(); it != content.end(); ++it)
    {
        Entity* tmp = *it;
        tmp->resurect();
    }
}