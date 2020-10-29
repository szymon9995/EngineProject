#pragma once

class Entity
{
protected:
int x;
int y;
    
public:
    virtual ~Entity() {};
    virtual void draw() {};
    virtual void update() {};
};