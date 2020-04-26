#include <iostream>
#include <assert.h>
#include "Chrono.h"
using namespace std;

int main(void)
{
    Chrono c;

    timespec_wait(timespec_from_ms(2000));
    assert(c.lap() - 2000 < 5);

    c.stop();
    timespec_wait(timespec_from_ms(1000));
    assert(c.lap() - 2000 < 5);

    c.restart();
    timespec_wait(timespec_from_ms(1000));
    assert(c.lap() - 1000 < 5);
    cout << "All test passed\n";
    return 0;
}