#pragma once
#include <vector>
#include "State.h"
#include "../AlClasses/AlTimer.h"
#include "../Engine/MainQueu.h"
class AnimationState
{
private:
    std::vector<State*> StateList;
    State *curState;
    AlTimer timer = AlTimer(0.5);
public:
    AnimationState(/* args */);
    ~AnimationState();

    void draw(int x,int y,int w,int h);
    void update();

    void addState(std::string stateName,std::string imagePath,int frameN,int w,int h);
    void addState(std::string stateName,AlImage &image,int frameN,int w,int h);
    void setState(std::string stateName);
    std::string getCurState();
};
