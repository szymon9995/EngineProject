#include "TilesImages.h"


TilesImages::TilesImages()
{
}

TilesImages::~TilesImages()
{
}

AlImage TilesImages::getGrassTile()
{
    return grassTile;
}

AlImage TilesImages::getLUSky()
{
    return LUSky;
}

AlImage TilesImages::getLDSky()
{
    return LDSky;
}

AlImage TilesImages::getRUSky()
{
    return RUSky;
}

AlImage TilesImages::getRDSky()
{
    return RDSky;
}

AlImage TilesImages::getMiddleSky()
{
    return MiddleSky;
}

AlImage TilesImages::getSky()
{
    return Sky;
}

AlImage TilesImages::getGrassRTile()
{
    return grassRTile;
}

AlImage TilesImages::getGrassLTile()
{
    return grassLTile;
}

AlImage TilesImages::getDirtTile()
{
    return dirtTile;
}

AlImage TilesImages::getDirtRTile()
{
    return dirtRTile;
}

AlImage TilesImages::getDirtLTile()
{
    return dirtLTile;
}

AlImage TilesImages::getDoorTile()
{
    return doorTile;
}

AlImage TilesImages::getCastleBrickTile()
{
    return castleBrickTile;
}

AlImage TilesImages::getCastleDirtTile()
{
    return castleDirtTile;
}

AlImage TilesImages::getBackBrickLTile()
{
    return backBrickLTile;
}

AlImage TilesImages::getBackBrickRTile()
{
    return backBrickRTile;
}

AlImage TilesImages::getBackBrickTile()
{
    return backBrickTile;
}

void TilesImages::LoadData()
{
    forestSprite.loadImage("images/Tiles/nature-tileset.png");
    castleSprite.loadImage("images/Tiles/castle-tileset.png");
    LoadTiles();
}

void TilesImages::LoadTiles()
{
    grassTile = forestSprite.cropOut(16,0,16,16);
    LUSky = forestSprite.cropOut(32,112,16,16);
    LDSky = forestSprite.cropOut(32,128,16,16);
    RUSky = forestSprite.cropOut(48,112,16,16);
    RDSky = forestSprite.cropOut(48,128,16,16);
    MiddleSky = forestSprite.cropOut(64,128,16,16);
    Sky = forestSprite.cropOut(64,160,16,16);
    grassRTile = forestSprite.cropOut(32,0,16,16);
    grassLTile = forestSprite.cropOut(0,0,16,16);
    dirtTile = forestSprite.cropOut(16,16,16,16);
    dirtRTile = forestSprite.cropOut(32,16,16,16);
    dirtLTile = forestSprite.cropOut(0,16,16,16);
    doorTile = forestSprite.cropOut(64,16,16,16);

    castleBrickTile = castleSprite.cropOut(16,16,16,16);
    castleDirtTile = castleSprite.cropOut(64,16,16,16);
    backBrickLTile = castleSprite.cropOut(32,48,16,16);
    backBrickRTile = castleSprite.cropOut(48,48,16,16);
    backBrickTile = castleSprite.cropOut(64,48,16,16);
}
