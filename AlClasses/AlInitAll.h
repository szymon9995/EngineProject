#pragma once
#include <iostream>


class AlInitAll//klasa inicjalizujaca dzialanie allegro5 i jego addonow
{
private:
    std::string ErrorMessage;
    bool DoIt();
public:
    AlInitAll(bool &test);//konstruktorm inicjalizacja allegro i jego wszyskich addonow,podaje sie zmienna by sprawdzic poprawnosc wykonania
    std::string ReturnError();//zwrot wiadomosci o bledzie, jezeli wystapil 
};