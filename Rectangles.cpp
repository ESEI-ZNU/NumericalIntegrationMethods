#include <iostream>
#include <math.h>
using namespace std;

#define f(x) exp(-x*-x)

/// <summary>
///    <para> Method of Rectangles </para>
/// </summary>
///<return>
///    <para> Turning code </para>
/// </return>
void rectangles()
{
	float a, b;
	int n;

	cout << "Lower limit of integration a = ";
	cin >> a;
	cout << "Upper limit of integration b = ";
	cin >> b;
	cout << "Number of subintervals n = ";
	cin >> n;

	float width = (b - a) / n;
	float rect_integ = 0;
	for (int step = 0; step < n; step++)
	{
		float x = a + step * width;
		rect_integ += width * f(x + 0.5 * width);
	}

	cout << "Integral is equal to: " << rect_integ << endl;
}