#include "Calibrator.h"
using namespace std;

Calibrator::Calibrator(double samplingPeriod, unsigned nSamples) : samples(nSamples), nSamples(nSamples)
{
    looper = Looper();
    start(samplingPeriod);
    looper.runLoop();
    for (unsigned i; i < nSamples - 1; i++)
    {
        // Calcul de a en faisant la moyenne des coefficients calculés par interpolation linéaire entre 2 échantillons consécutifs
        a += (samples[i + 1] - samples[i]) / (samplingPeriod * (nSamples - 1));
    }
    for (unsigned j; j < nSamples - 1; j++)
    {
        // Calcul de b en faisant la moyenne des valeurs de b obtenues à partir de la valeur de a calculée précédemment
        b += (samples[j] - (j + 1) * samplingPeriod) / (samplingPeriod * nSamples);
    }
}

double Calibrator::nLoops(double duration_ms)
{
    return a * duration_ms + b;
}

void Calibrator::callback()
{
    double sample;
    if (samples.size() < nSamples)
    {
        sample = looper.getSample();
    }
    else
    {
        double sample = looper.stopLoop();
        stop();
    }
}

Calibrator::CpuLoop::CpuLoop(Calibrator &calibrator) : calibrator(calibrator)
{
}

void Calibrator::CpuLoop::runtime(double duration_ms)
{
    double nLoops = calibrator.nLoops(duration_ms);
    timespec start, finish;
    clock_gettime(CLOCK_REALTIME, &start);
    runLoop(nLoops);
    clock_gettime(CLOCK_REALTIME, &finish);
    cout << "Theoretical time : " << timespec_to_ms(timespec_substract(finish, start)) << " ms" << endl;
    cout << "Practical time : " << timespec_to_ms(timespec_substract(finish, start)) << " ms" << endl;
}