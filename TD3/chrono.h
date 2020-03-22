#ifndef Chrono_h_INCLUDED
#define Chrono_h_INCLUDED
#include <iostream>
#include "../TD1/posixHelpers.h"
using namespace std;

class Chrono
{
private:
    timespec startTime_;
    timespec stopTime_;

public:
    Chrono();
    void stop();
    void restart();
    bool isActive();
    double startTime();
    double stopTime();
    double lap();
};
#endif