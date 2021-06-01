#include<iostream>
#include<cmath>

#define f(x) exp(-x*-x)

using namespace std;

/// <summary>
///    <para> Simpson's calculating function </para>
/// </summary>
void mainSimpson(double lowborder, double upborder, double subinterval)
{
    const double width = (upborder - lowborder) / subinterval;

    double simpson_integral = 0;
    for (int step = 0; step < subinterval; step++) {
        const double x1 = lowborder + step * width;
        const double x2 = lowborder + (step + 1) * width;

        simpson_integral += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f(0.5 * (x1 + x2)) + f(x2));
    }

    cout << "\nIntegration = " << simpson_integral << endl;
}