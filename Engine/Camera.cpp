#include "Camera.h"

#include "../Enitites/Player/Player.h"

Camera::Camera()
{
    player=NULL;
    screenHeight=0;
    screenWidth=0;

    position[0]=0;
    position[1]=0;
    
    isFixed=true;
}

Camera::~Camera()
{
    if(player!=NULL)
        player=NULL;
}

void Camera::setCameraScreenSize(int screenWidth,int screenHeight)
{
    this->screenWidth=screenWidth;
    this->screenHeight=screenHeight;
}

void Camera::UpdateCameraForeground()
{
    if(!isFixed)
    {
        position[0] = -(screenWidth/2) + (player->x +(player->w/2));
        position[1] = -(screenHeight/2) + (player->y +(player->h/2));
    }

    al_identity_transform(&camera);
    al_translate_transform(&camera,-position[0],-position[1]);
    al_use_transform(&camera);
    
}

void Camera::UpdateCameraBackround()
{
    al_identity_transform(&camera);
    al_use_transform(&camera);
}

void Camera::setCameraToPlayer(Player *player)
{
    this->player=player;
    isFixed=false;
}

void Camera::setCameraToPosition(int x,int y)
{
    if(player!=NULL)
        player=NULL;
    position[0]=x;
    position[1]=y;
    isFixed=true;
}

int Camera::getPosX()
{
    return position[0];
}

int Camera::getPosY()
{
    return position[1];
}