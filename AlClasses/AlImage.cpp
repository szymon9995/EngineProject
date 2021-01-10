#include "AlImage.h"


ALLEGRO_BITMAP* AlImage::GetBitmap()
{
    return bitmap;
}

AlImage::AlImage()
{
    bitmap = NULL;
}

AlImage::~AlImage()
{
    unLoadImage();
}

bool AlImage::loadImage(std::string path)
{
    if(bitmap!=NULL)
        unLoadImage();
    bitmap = al_load_bitmap(path.c_str());
    if(bitmap==NULL)
    {
        return false;
    }
    return true;
}

void AlImage::unLoadImage()
{
    if(bitmap!=NULL)
        al_destroy_bitmap(bitmap);
    bitmap=NULL;
}

AlImage& AlImage::cropOut(int x,int y,int w,int h)
{
    AlImage* tmp = new AlImage();
    if(bitmap==NULL)
        return *tmp;
    ALLEGRO_BITMAP *tmp2 = al_create_sub_bitmap(bitmap,x,y,w,h);
    tmp->loadImage(tmp2);
    al_destroy_bitmap(tmp2);
    return *tmp;
}

AlImage& AlImage::cropOut(AlImage& image,int x,int y,int w,int h)
{
    AlImage *tmp = new AlImage();
    if(image.GetBitmap()==NULL)
        return *tmp;
    ALLEGRO_BITMAP *tmp2 = al_create_sub_bitmap(image.GetBitmap(),x,y,w,h);
    tmp->loadImage(tmp2);
    al_destroy_bitmap(tmp2);
    return *tmp;

}

int AlImage::getWidth()
{
    return al_get_bitmap_width(bitmap);
}

int AlImage::getHeight()
{
    return al_get_bitmap_width(bitmap);
}

void AlImage::drawImage(int x, int y)
{
    if(bitmap!=NULL)
        al_draw_bitmap(bitmap,x,y,0);
}

void AlImage::drawScaledImage(int x,int y,double scale)
{
    if(bitmap!=NULL)
    {
        int bitmat_width = getWidth();
        int bitmat_height = getHeight();
        al_draw_scaled_bitmap(bitmap,0,0,bitmat_width,bitmat_height,x,y,bitmat_width*scale,bitmat_height*scale,0);
    }

}

void AlImage::drawScaledImage(int x,int y,int w,int h)
{
    if(bitmap!=NULL)
    {
        int bitmat_width = getWidth();
        int bitmat_height = getHeight();
        al_draw_scaled_bitmap(bitmap,0,0,bitmat_width,bitmat_height,x,y,w,h,0);
    }
}

void AlImage::drawReversedImage(int x,int y)
{
    if(bitmap!=NULL)
        al_draw_bitmap(bitmap,x,y,ALLEGRO_FLIP_HORIZONTAL);
}

void AlImage::drawReversedScaledImage(int x,int y,double scale)
{
    if(bitmap!=NULL)
    {
        int bitmat_width = getWidth();
        int bitmat_height = getHeight();
        al_draw_scaled_bitmap(bitmap,0,0,bitmat_width,bitmat_height,x,y,bitmat_width*scale,bitmat_height*scale,ALLEGRO_FLIP_HORIZONTAL);
    }
}

void AlImage::drawReversedScaledImage(int x,int y,int w,int h)
{
    if(bitmap!=NULL)
    {
        int bitmat_width = getWidth();
        int bitmat_height = getHeight();
        al_draw_scaled_bitmap(bitmap,0,0,bitmat_width,bitmat_height,x,y,w,h,ALLEGRO_FLIP_HORIZONTAL);
    }
}

//private

void AlImage::loadImage(ALLEGRO_BITMAP* image)
{
    if(image!=NULL)
        bitmap = al_clone_bitmap(image);
}
