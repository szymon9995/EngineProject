#pragma once

#include "../../AlClasses/AlImage.h"

class TilesImages
{
private:
    AlImage castleSprite;
    AlImage forestSprite;

    void LoadTiles();
    AlImage grassTile;
    AlImage LUSky;
    AlImage LDSky;
    AlImage RUSky;
    AlImage RDSky;
    AlImage MiddleSky;
    AlImage Sky;
    AlImage grassRTile;
    AlImage grassLTile;
    AlImage dirtTile;
    AlImage dirtRTile;
    AlImage dirtLTile;
    AlImage doorTile;
    AlImage castleBrickTile;
    AlImage castleDirtTile;
    AlImage backBrickRTile;
    AlImage backBrickLTile;
    AlImage backBrickTile;

    AlImage invalidTile;
public:
    TilesImages();
    ~TilesImages();

    AlImage& getGrassTile();
    AlImage& getLUSky();
    AlImage& getLDSky();
    AlImage& getRUSky();
    AlImage& getRDSky();
    AlImage& getMiddleSky();
    AlImage& getSky();
    AlImage& getGrassRTile();
    AlImage& getGrassLTile();
    AlImage& getDirtTile();
    AlImage& getDirtRTile();
    AlImage& getDirtLTile();
    AlImage& getDoorTile();

    AlImage& getCastleBrickTile();
    AlImage& getCastleDirtTile();
    AlImage& getBackBrickLTile();
    AlImage& getBackBrickRTile();
    AlImage& getBackBrickTile();

    AlImage& getTileImage(int id);

    void LoadData();
};
