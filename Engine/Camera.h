#pragma once

#include <allegro5/allegro.h>

typedef class Player Player;

class Camera
{
private:
    Player *player;
    int screenWidth;
    int screenHeight;

    bool isFixed;

    int position[2];
    struct ALLEGRO_TRANSFORM camera;
public:
    Camera();
    ~Camera();

    void setCameraScreenSize(int screenWidth,int screenHeight);

    void setCameraToPlayer(Player *player);
    void setCameraToPosition(int x,int y);

    void UpdateCameraForeground();
    void UpdateCameraBackround();
    int getPosX();
    int getPosY();

    bool canDraw(int x,int y,int w,int h);
};
