#include "Producer.h"

Producer::Producer(Semaphore &s, int id) : Thread(), id(id), s(s) {}

void Producer::run()
{
    s.take();
    cout << "\tLa tache " << this->id << " a pris un jeton\n";
    // Process
    timespec_wait(timespec_from_ms(100));
    s.give();
    cout << "\tLa tache " << this->id << " a donné un jeton\n";
}