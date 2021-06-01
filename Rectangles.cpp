#include <iostream>
#include <math.h>

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