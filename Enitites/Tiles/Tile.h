#pragma once

#include "../../AlAbstract/Entity.h"
#include "../Player/Player.h"
#include "../../Type/FloatRect.h"
#include "../../AlClasses/AlDrawable.h"
#include "../../AlClasses/AlImage.h"
#include "TilesImages.h"
#include "../../Engine/Camera.h"

class Tile : public Entity
{
protected:
    int x,y;
    int w,h;
    Player *player;
    Camera *camera;
    int tileID;

    static TilesImages* tileImages;
    bool canDraw=true;
public:
    Tile(int x,int y,int w,int h,int tileID,Player *player,Camera *camera);
    ~Tile();

    void draw();
    void update();

    static Tile* getTile(int x,int y,int w,int h,Player *player,Camera *camera,int id);
    static void initTiles();
    static void destroyTiles();
};