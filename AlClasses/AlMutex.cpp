#include "AlMutex.h"

#include <allegro5/allegro.h>

AlMutex::AlMutex() {
    mutex = al_create_mutex();
}

AlMutex::~AlMutex() {
    al_destroy_mutex(mutex);
}

void AlMutex::lock() {
    al_lock_mutex(mutex);
}

void AlMutex::unlock() {
    al_unlock_mutex(mutex);
}

ALLEGRO_MUTEX* AlMutex::getMutex()
{
    return mutex;
}