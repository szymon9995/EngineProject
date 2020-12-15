#pragma once

typedef class AlImage AlImage;

class AlAnimation
{
private:
//    AlImage sprite;
    int frame_width;
    int frame_height;
public:
    AlAnimation();
    ~AlAnimation();

    void setSprite(AlImage sprite,int frame_width,int frame_height);
};
