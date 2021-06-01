<<<<<<< Updated upstream
#include<iostream>
#include<math.h>

#define f(x) exp(-x*-x)

using namespace std;
=======
#include <iostream>
#include <math.h>

#define f(x) exp(-x*-x)

using namespace std;

>>>>>>> Stashed changes
/// <summary>
///    <para> Method of Trapezium </para>
/// </summary>
///<return>
///    <para> Turning code </para>
/// </return>
<<<<<<< Updated upstream
void trapezium()
=======
void trapezium(double lowborder, double upborder, double subinterval)
>>>>>>> Stashed changes
{
	float integration = 0.0, stepSize, k;

	//Calculation
	stepSize = (upborder - lowborder) / subinterval; //Finding step size 

	//Finding Integration Value
	integration = f(lowborder) + f(upborder);
	for (int i = 1; i <= subinterval - 1; i++)
	{
		k = lowborder + i * stepSize;
		integration = integration + 2 * (f(k));
	}
	integration = integration * stepSize / 2;

<<<<<<< Updated upstream
	cout << endl << "Integration = " << integration;
=======
	cout << endl << "Integration = " << integration << endl;
>>>>>>> Stashed changes
}