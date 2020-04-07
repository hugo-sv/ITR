#include <iostream>
#include <assert.h>
#include "CountDown.h"
using namespace std;

int main(void)
{
    CountDown t(40);
    cout << "sjfhjhj\n";
    t.start();
    timespec_wait(timespec_from_ms(3000));
    t.stop();
    return 0;
}