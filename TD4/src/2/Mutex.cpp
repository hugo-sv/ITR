#include "Mutex.h"

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

Mutex::Monitor::Monitor(Mutex &m)
{
    // Lock Mutex
    m.lock();
}
void Mutex::Monitor::wait()
{
    // pthread_mutex_lock(&p_counter->mutex);
    // while (p_counter->value > 0)
    // {
    //     pthread_cond_wait(&p_counter->isEmpty,
    //                       &p_counter->mutex);
    // }
    // pthread_mutex_unlock(&p_counter->mutex);

    // wait on posix condition
}
bool Mutex::Monitor::wait(double timeout_ms) {}
void Mutex::Monitor::notify() {}
void Mutex::Monitor::notifyAll()
{
    // pthread_mutex_lock(&p_counter->mutex);
    // if (p_counter->value > 0)
    // {
    //     p_counter->value -= 1; // Décrémentation
    //     pthread_cond_broadcast(
    //         &p_counter->isEmpty);
    // }
    // pthread_mutex_unlock(&p_counter->mutex);
}

Mutex::Lock::Lock(Mutex &m) : Mutex::Monitor::Monitor(m) {}
Mutex::Lock::Lock(Mutex &m, double timeout_ms) : Mutex::Monitor::Monitor(m) {}
Mutex::Lock::~Lock() {}
Mutex::TryLock::TryLock(Mutex &m) : Mutex::Monitor::Monitor(m) {}
Mutex::TryLock::~TryLock() {}

const char *Mutex::Monitor::TimeoutException::what() const noexcept
{
    return "Timeout waiting for condition";
}