#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>


class AlInitAll
{
private:
    std::string ErrorMessage;
    bool DoIt();
public:
    AlInitAll(bool &test);
    std::string ReturnError();
};

AlInitAll::AlInitAll(bool &test)
{
    test = DoIt();
}

bool AlInitAll::DoIt()
{
        if(!al_init())
        {
            ErrorMessage ="al_init Error";
            return false;
        }

        if(!al_init_primitives_addon())
        {
            ErrorMessage="Error al_init_primitives_addon";
            return false;
        }

        if(!al_install_keyboard())
        {
            ErrorMessage="Error al_isntall_keyboard";
            return false;
        }

        if(!al_install_mouse())
        {
            ErrorMessage="Error al_install_mouse";
            return false;
        }

        if(!al_init_image_addon())
        {
            ErrorMessage="Error al_init_image_addon";
            return false;
        }

        if(!al_init_font_addon())
        {
            ErrorMessage="Error al_init_font_addod";
            return false;
        }

        if(!al_init_acodec_addon())
        {
            ErrorMessage="Error al_init_acodec_addon";
            return false;
        }

        if(!al_install_audio())
        {
            ErrorMessage="Error al_install_audio";
            return false;
        }

        if(!al_init_ttf_addon())
        {
            ErrorMessage="Error al_init_ttf_addon";
            return false;
        }


        ErrorMessage="NoError";
        return true;
}

std::string AlInitAll::ReturnError()
{
    return ErrorMessage;
}