#pragma once

class Entity
{
protected:
int x;
int y;
int w;
int h;
    
public:
    virtual ~Entity() {};
    virtual void draw() {};
    virtual void update() {};
};