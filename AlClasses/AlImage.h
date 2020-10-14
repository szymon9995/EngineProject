#pragma once
#include <iostream>
#include <cstring>
#include <allegro5/allegro.h>

class AlImage
{
private:
    ALLEGRO_BITMAP *bitmap;
public:
    ALLEGRO_BITMAP* GetBitmap();

    AlImage(std::string path);
    AlImage(std::string path,bool &check);
    ~AlImage();
    
};

ALLEGRO_BITMAP* AlImage::GetBitmap()
{
    return bitmap;
}


AlImage::AlImage(std::string path)
{
    bitmap=al_load_bitmap(path.c_str());
    if(bitmap==NULL)
    {
        bitmap=al_create_bitmap(20,20);
    }
}

AlImage::AlImage(std::string path,bool &check)
{
    bitmap=al_load_bitmap(path.c_str());
    if(bitmap==NULL)
    {
        check=false;
        bitmap=al_create_bitmap(20,20);
    }
    else 
    {
        check=true;
    }
}

AlImage::~AlImage()
{
    if(bitmap!=NULL)
        al_destroy_bitmap(bitmap);
}