#include <iostream>
#include <math.h>

#define f(x) exp(-x*-x)

using namespace std;

/// <summary>
///    <para> Method of Trapezium </para>
/// </summary>
///<return>
///    <para> Turning code </para>
/// </return>
void trapezium(double lowborder, double upborder, double subinterval)
{
	float integration = 0.0, stepSize, k;

	stepSize = (upborder - lowborder) / subinterval; //Finding step size 

	integration = f(lowborder) + f(upborder);
	for (int i = 1; i <= subinterval - 1; i++)
	{
		k = lowborder + i * stepSize;
		integration = integration + 2 * (f(k));
	}
	integration = integration * stepSize / 2;

	cout << endl << "Integration = " << integration << endl;
}
