#include "CProducer.h"
namespace td4
{

CProducer::CProducer(Semaphore &s, int id) : Thread(), id(id), s(s) {}

void CProducer::run()
{
    // Taking a token
    this->s.take();
    cout << "\tProducer " << this->id << " took a token" << endl;
    // Process
    timespec_wait(timespec_from_ms(100));
    // Giving a token
    this->s.give();
    cout << "\tProducer " << this->id << " gave a token" << endl;
}

}