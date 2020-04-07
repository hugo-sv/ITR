#include <iostream>
#include <math.h>
#include "td1/posixHelpers.h"
using namespace std;

double timespec_to_ms(const timespec &time_ts)
{
    return (double)(time_ts.tv_sec * ms_PER_s + time_ts.tv_nsec / ns_PER_ms);
}

timespec timespec_from_ms(double time_ms)
{
    struct timespec ts;
    ts.tv_sec = (long)floor(time_ms / ms_PER_s);
    ts.tv_nsec = (long)abs((time_ms - ts.tv_sec * ms_PER_s) * ns_PER_ms);
    if (ts.tv_nsec < 0)
    {
        ts.tv_nsec += ns_PER_s;
    }
    return ts;
}

timespec timespec_now()
{
    struct timespec abstime;
    clock_gettime(CLOCK_REALTIME, &abstime);
    return abstime;
}

// Function displaying a timespec attributes
void print_time(const timespec &time_ts)
{
    cout << "secondes: " << time_ts.tv_sec << "\n";
    cout << "nanosecondes: " << time_ts.tv_nsec << "\n";
    cout << "microsecondes: " << timespec_to_ms(time_ts) << endl;
}

timespec timespec_negate(const timespec &time_ts)
{
    return timespec_from_ms(-timespec_to_ms(time_ts));
}

timespec timespec_add(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_from_ms(timespec_to_ms(time1_ts) + timespec_to_ms(time2_ts));
}

timespec timespec_substract(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_add(time1_ts, timespec_negate(time2_ts));
}

timespec timespec_try_wait(const timespec &delay_ts)
{
    struct timespec tp;
    if (nanosleep(&delay_ts, &tp) == -1)
    {
        return tp;
    }
    return timespec_from_ms(0);
}

timespec timespec_wait(const timespec &delay_ts)
{
    struct timespec tp_temp;
    tp_temp = timespec_try_wait(delay_ts);
    while (timespec_to_ms(tp_temp) != 0)
    {
        tp_temp = timespec_wait(tp_temp);
    }
    return tp_temp;
}

timespec operator-(const timespec &time_ts)
{
    return timespec_negate(time_ts);
}
timespec operator+(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_add(time1_ts, time2_ts);
}
timespec operator-(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_substract(time1_ts, time2_ts);
}
timespec &operator+=(timespec &time_ts, const timespec &delay_ts)
{
    time_ts = time_ts + delay_ts;
    return time_ts;
}
timespec &operator-=(timespec &time_ts, const timespec &delay_ts)
{
    time_ts = time_ts - delay_ts;
    return time_ts;
}
bool operator==(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_to_ms(time1_ts) == timespec_to_ms(time2_ts);
}
bool operator!=(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_to_ms(time1_ts) != timespec_to_ms(time2_ts);
}
bool operator<(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_to_ms(time1_ts) < timespec_to_ms(time2_ts);
}
bool operator>(const timespec &time1_ts, const timespec &time2_ts)
{
    return timespec_to_ms(time1_ts) > timespec_to_ms(time2_ts);
}