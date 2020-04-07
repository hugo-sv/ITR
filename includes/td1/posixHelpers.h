#include <iostream>
#include <math.h>
#ifndef Posix_h_INCLUDED
#define Posix_h_INCLUDED
using namespace std;

// Constants
static const long ns_PER_s = 1000000000;
static const long us_PER_s = 1000000;
static const long ms_PER_s = 1000;
static const long ns_PER_ms = ns_PER_s / ms_PER_s;

double timespec_to_ms(const timespec &time_ts);

timespec timespec_from_ms(double time_ms);

timespec timespec_now();

// Function displaying a timespec attributes
void print_time(const timespec &time_ts);

timespec timespec_negate(const timespec &time_ts);

timespec timespec_add(const timespec &time1_ts, const timespec &time2_ts);

timespec timespec_substract(const timespec &time1_ts, const timespec &time2_ts);

timespec timespec_try_wait(const timespec &delay_ts);

timespec timespec_wait(const timespec &delay_ts);

timespec operator-(const timespec &time_ts);
timespec operator+(const timespec &time1_ts, const timespec &time2_ts);
timespec operator-(const timespec &time1_ts, const timespec &time2_ts);
timespec &operator+=(timespec &time_ts, const timespec &delay_ts);
timespec &operator-=(timespec &time_ts, const timespec &delay_ts);
bool operator==(const timespec &time1_ts, const timespec &time2_ts);
bool operator!=(const timespec &time1_ts, const timespec &time2_ts);
bool operator<(const timespec &time1_ts, const timespec &time2_ts);
bool operator>(const timespec &time1_ts, const timespec &time2_ts);
#endif