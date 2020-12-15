#include "AlAnimation.h"

#include "AlImage.h"

AlAnimation::AlAnimation()
{

}

AlAnimation::~AlAnimation()
{

}

void AlAnimation::setSprite(AlImage sprite,int frame_width,int frame_height)
{
//    this->sprite=sprite;
    this->frame_width=frame_width;
    this->frame_height=frame_height;
}
