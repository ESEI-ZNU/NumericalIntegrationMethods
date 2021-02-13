#include<iostream>
#include<math.h>
#define f(x) exp(-x*-x)
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float lower, upper, integration = 0.0, stepSize, k, subInterval;

	//input
	cout << "Enter lower limit of integration: ";
	cin >> lower;
	cout << "Enter upper limit of integration: ";
	cin >> upper;
	cout << "Enter number of sub intervals: ";
	cin >> subInterval;

	//Calculation
	stepSize = (upper - lower) / subInterval; //Finding step size 

	//Finding Integration Value
	integration = f(lower) + f(upper);
	for (int i = 1; i <= subInterval - 1; i++)
	{
		k = lower + i * stepSize;
		integration = integration + 2 * (f(k));
	}
	integration = integration * stepSize / 2;

	cout << endl << "Integration = " << integration;
}