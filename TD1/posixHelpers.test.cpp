#include "posixHelpers.cpp"
#include <assert.h>
#include <unistd.h>
using namespace std;

int main()
{
    double ms = 3200;
    struct timespec tp1, tp2, tp3, tp4, tp5, tp6, tp7;
    tp1 = timespec_from_ms(ms);
    tp2 = timespec_from_ms(-ms);
    // Testing timespec_to_ms and timespec_from_ms
    assert(abs(timespec_to_ms(tp1) + timespec_to_ms(tp2)) < 1);
    // Testing - operator
    assert(abs(timespec_to_ms(-tp1) + timespec_to_ms(tp1)) < 1);
    // Testing timespec_now
    tp3 = timespec_now();
    sleep(1);
    tp4 = timespec_now();
    assert(timespec_to_ms(tp4) - timespec_to_ms(tp3) - 1000 < 10);
    // Testing + and - operators ( using Addition, substraction and negate )
    assert(abs(timespec_to_ms(tp4) + timespec_to_ms(tp3) - timespec_to_ms(tp4 + tp3)) < 1);
    assert(abs(timespec_to_ms(tp4) - timespec_to_ms(tp3) - timespec_to_ms(tp4 - tp3)) < 1);
    // Testing timespec_wait
    tp5 = timespec_now();
    tp6 = timespec_wait(timespec_from_ms(1000));
    tp7 = timespec_now();
    assert(timespec_to_ms(tp5) - timespec_to_ms(tp7) - 1000 < 10 && timespec_to_ms(tp6) == 0);
    // Testing += and -= operators
    tp1 += tp2;
    assert(timespec_to_ms(tp1) == 0);
    tp2 -= tp2;
    assert(timespec_to_ms(tp2) == 0);
    cout << "All other tests passed.\n";
    return 0;
}