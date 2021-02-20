#include <iostream>
#include <math.h>
using namespace std;


float f(float x)
{
	return exp(-x * -x);
}


float rect_integ(float a, float b, int n)
{
	float width = (b - a) / n;
	float rect_integ = 0;
	for (int step = 0; step < n; step++)
	{
		float x = a + step * width;
		rect_integ += width * f(x + 0.5 * width);
	}
	return rect_integ;
}


int main()
{
	float a, b;
	int n;
	cout << "Method of Rectangles" << endl;
	cout << "Lower limit of integration a = ";
	cin >> a;
	cout << "Upper limit of integration b = ";
	cin >> b;
	cout << "Number of subintervals n = ";
	cin >> n;
	cout << "Integral is equal to: " << rect_integ(a, b, n) << endl;
    return 0;
}