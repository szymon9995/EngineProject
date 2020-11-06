#pragma once
#include <allegro5/allegro.h>
#include "AlMutex.h"

class AlCond {
private:
    ALLEGRO_COND *cond;
public:
    AlCond();
    ~AlCond();

    void wait(AlMutex mutex);
    void broadcast();
    void signal();
};

AlCond::AlCond() {
    cond = al_create_cond();
}

AlCond::~AlCond() {
    al_destroy_cond(cond);
}

void AlCond::wait(AlMutex mutex) {
    al_wait_cond(cond, mutex.getMutex());
}

void AlCond::broadcast() {
    al_broadcast_cond(cond);
}

void AlCond::signal() {
    al_signal_cond(cond);
}
