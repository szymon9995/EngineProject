#include "AnimationState.h"


AnimationState::AnimationState()
{
    curState = NULL;
    MainQueu::getQuee()->Register(timer.TimerEvent());
    timer.Start();
}

AnimationState::~AnimationState()
{
    while(!StateList.empty())
    {
        delete StateList.back();
        StateList.pop_back();
    }
}

void AnimationState::draw(int x,int y,int w,int h)
{
    if(curState!=NULL)
        curState->getCurImage().drawScaledImage(x,y,w,h);
}

void AnimationState::update()
{
    if(MainQueu::getQuee()->IsEventSource(timer.TimerEvent()))
    {
        if(curState!=NULL)
            curState->incrementState();
    }
}

void AnimationState::addState(std::string stateName,std::string imagePath,int frameN,int w,int h)
{
    StateList.push_back(new State(stateName));
    StateList.back()->setStateFrames(imagePath,frameN,w,h);
    if(curState==NULL)
        curState = StateList.back();
}

void AnimationState::addState(std::string stateName,AlImage &image,int frameN,int w,int h)
{
    StateList.push_back(new State(stateName));
    StateList.back()->setStateFrames(image,frameN,w,h);
    if(curState==NULL)
        curState = StateList.back();
}

void AnimationState::setState(std::string stateName)
{
    if(curState->getName() ==stateName)
        return;
    for (std::vector<State *>::iterator it=StateList.begin(); it != StateList.end(); ++it)
    {
        if((*it)->getName() == stateName)
        {
            curState = *it;
            break;
        }
            
    }
}

std::string AnimationState::getCurState()
{
    if(curState==NULL)
        return "";
    return curState->getName();
}