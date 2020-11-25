#pragma once

typedef struct ALLEGRO_COND ALLEGRO_COND;
typedef class AlMutex AlMutex;

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
