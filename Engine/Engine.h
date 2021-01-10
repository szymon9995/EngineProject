#pragma once

#include <iostream>
#include <allegro5/allegro.h>
#include "../AlClasses/AlInitAll.h"
#include "../AlClasses/AlDisplay.h"
#include "../AlClasses/AlImage.h"
#include "../AlClasses/AlFont.h"
#include "../AlClasses/AlTimer.h"
#include "../AlClasses/AlEventQueue.h"
#include "../AlClasses/AlKeyboard.h"
#include "../AlClasses/AlMouse.h"
#include "../AlClasses/AlDrawable.h"

#include "StartUpConfig.h"
#include "SceneManager.h"

/**
 * \brief klasa Engine
 *
 * Klasa zajmujaca sie podstawowym dzialem programu.
 *
 * \version wersja alfa
 */

class Engine
{
private:
    bool canBeStarted;

    static Engine* engine;

    AlDisplay display;//Ekran programu (przyjmujemy ze jest tylko 1)
    StartUpConfig strartup;//pliki konfiguracyjne startu programu
    SceneManager manager;//Manager scen(poziomow), zajmuje sie ich ryowaniem, aktualizacja i zmienainiem scen

    void UpdateDisplay();//aktualizacja okna ekranu

    void InitDisplay();//inicjalizacja okna programu
    Engine();//konstruktor silnikas
public:
    
    ~Engine();//dekonstruktor silnika

    void Start();//start silnika

    static Engine* getEngine();
    static void destroyEngine();
};