#pragma once

#include "../../AlAbstract/Entity.h"
#include "../Player/Player.h"
#include "../../Type/FloatRect.h"
#include "../../AlClasses/AlDrawable.h"
#include "../../AlClasses/AlImage.h"
#include "TilesImages.h"

class Tile : public Entity
{
protected:
    int x,y;
    int w,h;
    Player *player;
    int tileID;

    static TilesImages* tileImages;

public:
    Tile(int x,int y,int w,int h,int tileID,Player *player);
    ~Tile();

    void draw();
    void update();

    static Tile* getTile(int x,int y,int w,int h,Player *player,int id);
    static void initTiles();
    static void destroyTiles();
};