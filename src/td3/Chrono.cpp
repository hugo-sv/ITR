#include "Chrono.h"
namespace td3
{

Chrono::Chrono()
{
    this->startTime_ = timespec_now();
    this->stopTime_ = timespec_from_ms(0);
}

void Chrono::stop()
{
    this->stopTime_ = timespec_now();
}
void Chrono::restart()
{
    this->startTime_ = timespec_now();
    this->stopTime_ = timespec_from_ms(0);
}
bool Chrono::isActive()
{
    return this->stopTime() == 0;
}
double Chrono::startTime()
{
    return timespec_to_ms(this->startTime_);
}
double Chrono::stopTime()
{
    return timespec_to_ms(this->stopTime_);
}
double Chrono::lap()
{
    if (this->isActive())
    {
        return timespec_to_ms(timespec_now()) - this->startTime();
    }
    return this->stopTime() - this->startTime();
}

}