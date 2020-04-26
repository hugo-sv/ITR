#include "posixHelpers.h"
#include <assert.h>
#include <unistd.h>
using namespace std;
using namespace td1;

int main()
{
    double a_ms = 3200;
    struct timespec a_ts, b_ts, c_ts, d_ts, e_ts, f_ts, g_ts;

    a_ts = timespec_from_ms(a_ms);
    b_ts = timespec_from_ms(-a_ms);
    assert(abs(timespec_to_ms(a_ts) + timespec_to_ms(b_ts)) < 1);
    cout << "timespec_to_ms and timespec_from_ms tested\n";

    assert(abs(timespec_to_ms(timespec_negate(a_ts)) + timespec_to_ms(a_ts)) < 1);
    cout << "negate operator tested\n";

    assert(abs(timespec_to_ms(-a_ts) + timespec_to_ms(a_ts)) < 1);
    cout << "negate - operator tested\n";

    c_ts = timespec_now();
    sleep(1);
    d_ts = timespec_now();
    assert(timespec_to_ms(d_ts) - timespec_to_ms(c_ts) - 1000 < 10);
    cout << "timespec_now tested\n";

    assert(abs(timespec_to_ms(d_ts) + timespec_to_ms(c_ts) - timespec_to_ms(timespec_add(d_ts, c_ts))) < 1);
    cout << "add operator tested\n";

    assert(timespec_to_ms(timespec_add(d_ts, c_ts)) == timespec_to_ms(d_ts + c_ts));
    cout << "+ operators tested\n";

    assert(abs(timespec_to_ms(d_ts) - timespec_to_ms(c_ts) - timespec_to_ms(timespec_substract(d_ts, c_ts))) < 1);
    cout << "substarct operator tested\n";

    assert(timespec_to_ms(timespec_substract(d_ts, c_ts)) == timespec_to_ms(d_ts - c_ts));
    cout << "- operators tested\n";

    e_ts = timespec_now();
    f_ts = timespec_wait(timespec_from_ms(1000));
    g_ts = timespec_now();
    assert(timespec_to_ms(e_ts) - timespec_to_ms(g_ts) - 1000 < 10 && timespec_to_ms(f_ts) == 0);
    cout << "timespec_wait tested\n";

    a_ts += b_ts;
    assert(timespec_to_ms(a_ts) == 0);
    cout << "+= tested\n";

    b_ts -= b_ts;
    assert(timespec_to_ms(b_ts) == 0);
    cout << "-= tested\n";

    cout << "All tests passed.\n";
    return 0;
}
