#pragma once

typedef struct ALLEGRO_TIMER ALLEGRO_TIMER;
typedef struct ALLEGRO_EVENT_SOURCE ALLEGRO_EVENT_SOURCE;

class AlTimer//kalsas do trzymania timera
{
private:
    ALLEGRO_TIMER *clock;
public:
    void Start(); //start timera
    void Stop(); //zatrzymeranie timera
    void Resume(); //wznowienie timera
    int GetCount(); //dostanie ilosci cyklow przebytych przez timer
    void SetCount(int set);//ustawienie licznika cyklow dla timera
    void AddCount(int add);//dodanie ilosci cyklow to licznika timera
    double GetSpeed();//dostanie z jaka szybkoscia/czestotliwoscia dziala timer
    void SetSpeed(double speed);//zmienie czasu timera na inny podany
    ALLEGRO_EVENT_SOURCE* TimerEvent();//Dostanie  zrodla wydarzenia od specificznego timera
    ALLEGRO_TIMER* GetTimer(); //Dostanie wskaznika na timer z allegro5

    AlTimer(double speed); //tworznie timera, podajemy z jaką preskoscia/czestotliwoscia ma pracowac
    ~AlTimer();//Destruktor timera
};