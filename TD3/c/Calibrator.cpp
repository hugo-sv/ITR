#include "Calibrator.h"
using namespace std;

Calibrator::Calibrator(double samplingPeriod, unsigned nSamples) : nSamples(nSamples)
{
    looper = Looper();
    samples = std::vector<double>();
    start(samplingPeriod);
    looper.runLoop();
    for(unsigned i = 0; i < nSamples - 1; i++)
    {
        // Calcul de a en faisant la moyenne des coefficients calculés par interpolation linéaire entre 2 échantillons consécutifs
        a += (samples[i+1] - samples[i])/(samplingPeriod * (nSamples - 1));
    }
    for(unsigned j = 0; j < nSamples; j++)
    {
        // Calcul de b en faisant la moyenne des valeurs de b obtenues à partir de la valeur de a calculée précédemment
        b += (samples[j] - (j+1) * samplingPeriod * a)/(samplingPeriod * nSamples);
    }
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

double Calibrator::nLoops(double duration_ms)
{
    return a * duration_ms + b;
}

void Calibrator::callback()
{
    double sample;
    if(samples.size() < nSamples)
    {
        sample = looper.getSample();
    }
    else
    {
        sample = looper.stopLoop();
        stop();  
    }
    samples.push_back(sample);
}

Calibrator::CpuLoop::CpuLoop(Calibrator& calibrator) : calibrator(calibrator)
{

}

void Calibrator::CpuLoop::runtime(double duration_ms)
{
    double nLoops = calibrator.nLoops(duration_ms);
    cout << "Number of Loops = " << nLoops << endl;
    timespec start, finish;
    clock_gettime(CLOCK_REALTIME, &start);
    runLoop(nLoops);
    clock_gettime(CLOCK_REALTIME, &finish);
    cout<< "Theoretical time : " << duration_ms << " ms" << endl;
    cout<< "Practical time : " << timespec_to_ms(timespec_subtract(finish, start)) << " ms" << endl;
}