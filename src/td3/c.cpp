#include <iostream>
#include <assert.h>
#include "Calibrator.h"
#include "Looper.h"
using namespace std;
using namespace td3;

int main(void)
{
    Calibrator calibrator = Calibrator(1.0, 1000);
    Calibrator::CpuLoop cpuLoop1 = Calibrator::CpuLoop(calibrator);
    cpuLoop1.runtime(4000.0);
    Calibrator::CpuLoop cpuLoop2 = Calibrator::CpuLoop(calibrator);
    cpuLoop2.runtime(6000.0);
    return 0;
}