#include "td1/posixHelpers.h"
#include <assert.h>
#include <unistd.h>
using namespace std;

int main()
{
    double ms = 3200;
    struct timespec tp1, tp2, tp3, tp4, tp5, tp6, tp7;

    tp1 = timespec_from_ms(ms);
    tp2 = timespec_from_ms(-ms);
    assert(abs(timespec_to_ms(tp1) + timespec_to_ms(tp2)) < 1);
    cout << "timespec_to_ms and timespec_from_ms tested\n";

    assert(abs(timespec_to_ms(-tp1) + timespec_to_ms(tp1)) < 1);
    cout << "- operator tested\n";

    tp3 = timespec_now();
    sleep(1);
    tp4 = timespec_now();
    assert(timespec_to_ms(tp4) - timespec_to_ms(tp3) - 1000 < 10);
    cout << "timespec_now tested\n";

    assert(abs(timespec_to_ms(tp4) + timespec_to_ms(tp3) - timespec_to_ms(timespec_add(tp4, tp3))) < 1);
    cout << "add operator tested\n";

    assert(timespec_to_ms(timespec_add(tp4, tp3)) == timespec_to_ms(tp4 + tp3));
    cout << "+ operators tested\n";

    assert(abs(timespec_to_ms(tp4) - timespec_to_ms(tp3) - timespec_to_ms(timespec_substract(tp4, tp3))) < 1);
    cout << "substarct operator tested\n";

    assert(timespec_to_ms(timespec_substract(tp4, tp3)) == timespec_to_ms(tp4 - tp3));
    cout << "- operators tested\n";

    tp5 = timespec_now();
    tp6 = timespec_wait(timespec_from_ms(1000));
    tp7 = timespec_now();
    assert(timespec_to_ms(tp5) - timespec_to_ms(tp7) - 1000 < 10 && timespec_to_ms(tp6) == 0);
    cout << "timespec_wait tested\n";

    tp1 += tp2;
    assert(timespec_to_ms(tp1) == 0);
    cout << "+= tested\n";

    tp2 -= tp2;
    assert(timespec_to_ms(tp2) == 0);
    cout << "-= tested\n";

    cout << "All tests passed.\n";
    return 0;
}