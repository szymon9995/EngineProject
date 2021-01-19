#include "State.h"

State::State(std::string state_name)
{
    this->state_name=state_name;
}

State::~State()
{
    while(!imageList.empty())
    {
        delete imageList.back();
        imageList.pop_back();
    }
}

std::string State::getName()
{
    return state_name;
}

void State::incrementState()
{
    frameCur++;
    if(frameCur>=frameAmount)
        frameCur=0;
}

AlImage& State::getCurImage()
{
    return *imageList[frameCur];
}

void State::setStateFrames(std::string imagePath,int frameN,int w,int h)
{
    AlImage tmp;
    tmp.loadImage(imagePath);
    int imgW = tmp.getWidth();
    int x=0;
    int y=0;
    frameAmount = frameN;
    for(int i=0;i<frameN;i++)
    {
        imageList.push_back(&tmp.cropOut(x,y,w,h));
        x+=w;
        if(x>=imgW)
        {
            x=0;
            y+=h;
        }
    }
    
}

void State::setStateFrames(AlImage &image,int frameN,int w,int h)
{
    int imgW = image.getWidth();
    int x=0;
    int y=0;
    frameAmount = frameN;
    for(int i=0;i<frameN;i++)
    {
        imageList.push_back(&image.cropOut(x,y,w,h));
        x+=w;
        if(x>=imgW)
        {
            x=0;
            y+=h;
        }
    }
}
