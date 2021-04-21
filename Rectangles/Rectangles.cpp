#include <iostream>
#include <math.h>
using namespace std;

float f(float x)
{
	return exp(-x * -x);
}

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

int main()
{
	rectangles();
}