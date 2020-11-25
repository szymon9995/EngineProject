#pragma once

typedef struct ALLEGRO_MUTEX ALLEGRO_MUTEX;

class AlMutex {
private:
    ALLEGRO_MUTEX *mutex;
public:
    AlMutex();
    ~AlMutex();

    void lock();
    void unlock();
    ALLEGRO_MUTEX* getMutex();
};