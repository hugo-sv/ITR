#ifndef Calibrator_h_INCLUDED
#define Calibrator_h_INCLUDED
#include <iostream>
#include <vector>
#include "../TD1/posixHelpers.h"
using namespace std;

class Calibrator
{
private:
    double a;
    double b;
    vector<double> samples;

public:
    Calibrator(double samplingPeriod_ms, unsigned nSamples);
    double nLoops(double duration_ms);

protected:
    callback();
};
#endif