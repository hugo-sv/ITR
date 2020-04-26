#include "Mutex.h"
namespace td4
{

Mutex::Mutex()
{
    // Initialize posixID and posixCondId
    pthread_mutexattr_t mutexAttribute;
    pthread_mutexattr_init(&mutexAttribute);
    pthread_mutexattr_settype(&mutexAttribute, PTHREAD_MUTEX_RECURSIVE);

    pthread_mutex_init(&this->posixId, &mutexAttribute);
    pthread_mutexattr_destroy(&mutexAttribute);

    pthread_cond_init(&this->posixCondId, nullptr);
}
Mutex::~Mutex()
{
    // Destroy posixID and posixCondId
    pthread_mutex_destroy(&this->posixId);
    pthread_cond_destroy(&this->posixCondId);
}
void Mutex::lock()
{
    pthread_mutex_lock(&this->posixId);
}
bool Mutex::lock(double timeout_ms)
{
    timespec deadline = timespec_now() + timespec_from_ms(timeout_ms);
    return !(pthread_mutex_timedlock(&this->posixId, &deadline) == ETIMEDOUT);
}
bool Mutex::trylock()
{
    return this->lock(0);
}
void Mutex::unlock()
{
    pthread_mutex_unlock(&this->posixId);
}

Mutex::Monitor::Monitor(Mutex &m) : m(m)
{
}

void Mutex::Monitor::wait()
{
    pthread_cond_wait(&this->m.posixCondId, &this->m.posixId);
}
bool Mutex::Monitor::wait(double timeout_ms)
{
    timespec deadline = timespec_now() + timespec_from_ms(timeout_ms);
    return !(pthread_cond_timedwait(&this->m.posixCondId, &this->m.posixId, &deadline) == ETIMEDOUT);
}
void Mutex::Monitor::notify()
{
    pthread_cond_signal(&this->m.posixCondId);
}
void Mutex::Monitor::notifyAll()
{
    pthread_cond_broadcast(&this->m.posixCondId);
}

Mutex::Lock::Lock(Mutex &m) : Mutex::Monitor::Monitor(m)
{
    this->m.lock();
}
Mutex::Lock::Lock(Mutex &m, double timeout_ms) : Mutex::Monitor::Monitor(m)
{
    if (!this->m.lock(timeout_ms))
    {
        throw TimeoutException();
    }
}
Mutex::Lock::~Lock()
{
    this->m.unlock();
}
Mutex::TryLock::TryLock(Mutex &m) : Mutex::Monitor::Monitor(m)
{
    if (!this->m.trylock())
    {
        throw TimeoutException();
    }
}
Mutex::TryLock::~TryLock()
{
    this->m.unlock();
}

Mutex::Monitor::TimeoutException::TimeoutException() : exception()
{
}

const char *Mutex::Monitor::TimeoutException::what() const noexcept
{
    return "Timeout waiting for condition";
}

}