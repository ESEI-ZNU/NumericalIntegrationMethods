#include <iostream>
#include <math.h>
using namespace std;

#define f(x) exp(-x*-x)

void rectangles()
{
    float left, right;
    int step;

    cout << "Enter lower limit of integration: ";
    cin >> left;
    cout << "Enter upper limit of integration: ";
    cin >> right;
    cout << "Enter number of sub intervals: ";
    cin >> step;

   
    double sum = 0;
    double runner;
      
    /* rectangular formula */
    for(runner = left + step * 0.5; runner < right; runner += step)
        sum += f(runner);
    sum *= step;
            
    cout << "\nIntegration = " << sum << endl;
}
