#ifndef Calibrator_h_INCLUDED
#define Calibrator_h_INCLUDED
#include <iostream>
#include <vector>
#include "../../TD1/posixHelpers.h"
#include "../b/PeriodicTimer.h"
#include "Looper.h"
using namespace std;

class Calibrator : public PeriodicTimer
{
public:
    class CpuLoop;
public:
    Calibrator(double samplingPeriod_ms, unsigned nSamples);
    double nLoops(double duration_ms);
protected:
    void callback();
private:
    double a;
    double b;
    unsigned nSamples;
    vector<double> samples;
    Looper looper;
};

class Calibrator::CpuLoop : public Looper
{
public:
    CpuLoop(Calibrator& calibrator);
    void runtime(double duration_ms);
private:
    Calibrator& calibrator;
};
#endif