#ifndef Fifo_hpp_INCLUDED
#define Fifo_hpp_INCLUDED
#include "Mutex.h"
#include <queue>
using namespace std;

template <class T>
class Fifo
{
private:
    std::queue<T> elements;
    Mutex m;

public:
    class EmptyException
    {
    };
    Fifo();
    void push(T element);
    T pop();
    T pop(double timeout_ms);
    bool empty();
};

template <class T>
Fifo<T>::Fifo()
{
    this->m = Mutex();
    this->elements = std::queue<T>();
}

template <class T>
void Fifo<T>::push(T element)
{
    Mutex::Lock l(this->m);
    this->elements.push(element);
    l.notifyAll();
}

template <class T>
T Fifo<T>::pop()
{
    Mutex::Lock l(this->m);
    while (this->elements.empty())
    {
        l.wait();
    }
    T element = elements.front();
    this->elements.pop();
    return element;
}

template <class T>
T Fifo<T>::pop(double timeout_ms)
{
    timespec deadline = timespec_now() + timespec_from_ms(timeout_ms);
    Mutex::Lock l(this->m);
    while (this->elements.empty() && deadline > timespec_now())
    {
        l.wait(timespec_to_ms(deadline - timespec_now()));
    }
    if (deadline > timespec_now())
    {
        T element = elements.front();
        this->elements.pop();
        return element;
    }
    else
    {
        throw EmptyException();
    }
}

template <class T>
bool Fifo<T>::empty()
{
    return this->elements.empty();
}

#endif