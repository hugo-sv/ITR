#ifndef td3_Chrono_h_INCLUDED
#define td3_Chrono_h_INCLUDED
#include <iostream>
#include "../td1/posixHelpers.h"
using namespace td1;
using namespace std;

namespace td3
{

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

}

#endif