#pragma once
#include "../AlClasses/AlImage.h"
#include <vector>


class State
{
private:
    std::string state_name;
    int frameAmount = 0;
    int frameCur = 0;
    std::vector<AlImage *> imageList;
public:
    State(std::string state_name);
    ~State();

    std::string getName();
    void incrementState();
    AlImage& getCurImage();
    void setStateFrames(std::string imagePath,int frameN,int w,int h);
    void setStateFrames(AlImage &image,int frameN,int w,int h);
};