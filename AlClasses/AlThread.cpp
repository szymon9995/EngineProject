#include "AlThread.h"

#include <allegro5/allegro.h>

void AlThread::start() {
    al_start_thread(thread);
}

void AlThread::join(void **ret_value) {
    al_join_thread(thread,ret_value);
}

void AlThread::tell_to_stop() {
    al_set_thread_should_stop(thread);
}

bool AlThread::should_stop() {
    return al_get_thread_should_stop(thread);
}

AlThread::AlThread(void *(*proc)(ALLEGRO_THREAD *thread, void *arg), void *arg) {
    thread = al_create_thread(proc,arg);
}

AlThread::~AlThread() {
    al_destroy_thread(thread);
}
