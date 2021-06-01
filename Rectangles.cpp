#include <iostream>
#include <math.h>
<<<<<<< Updated upstream
using namespace std;

#define f(x) exp(-x*-x)

/// <summary>
///    <para> Method of Rectangles </para>
/// </summary>
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
=======

#define f(x) exp(-x*-x)

using namespace std;

/// <summary>
///    <para> Method of Rectangles </para>
/// </summary>
void rectangles(double lowborder, double upborder, double subinterval)
{
    float sum = 0, runner;

    /* rectangular formula */
    for (runner = lowborder + subinterval * 0.5; runner < upborder; runner += subinterval)
    {
        sum += f(runner);
        sum *= subinterval;
    }

    cout << "\nIntegration = " << sum << endl;
}
>>>>>>> Stashed changes
