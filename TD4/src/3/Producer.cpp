#include "Producer.h"

Producer::Producer(Semaphore &s, int id) : Thread(), id(id), s(s) {}

void Producer::run()
{
    this->s.take();
    cout << "\tProducer " << this->id << " took a token\n";
    // Process
    timespec_wait(timespec_from_ms(100));
    this->s.give();
    cout << "\tProducer " << this->id << " gave a token\n";
}