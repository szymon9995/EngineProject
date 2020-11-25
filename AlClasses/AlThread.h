#pragma once

typedef struct ALLEGRO_THREAD ALLEGRO_THREAD;

class AlThread//kalsa do trzymania watka
{
private:
    ALLEGRO_THREAD *thread;
public:
    void start();//zaczecie watku
    void join(void **ret_value);//funkcja 'joinujaca' watek, wraca go do glownego procesu
    void tell_to_stop();//funcka mowiaca watkowi by sie zatrzymal
    bool should_stop();//funckja sprawdzajaca czy watek powinnien sie zatrzymac

    AlThread(void *(*proc)(ALLEGRO_THREAD *thread, void *arg), void *arg);//konstruktor watku
    ~AlThread();//destruktor watku
};