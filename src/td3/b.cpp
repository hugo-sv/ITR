#include <iostream>
#include <assert.h>
#include "CountDown.h"
using namespace std;
using namespace td3;

int main(void)
{
    CountDown t(40);
    cout << "Countdown started at 40\n";
    t.start();
    timespec_wait(timespec_from_ms(41000));
    t.stop();
    return 0;
}