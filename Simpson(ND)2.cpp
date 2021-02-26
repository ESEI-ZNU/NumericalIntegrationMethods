#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
	return exp(-x * -x);
}

float simpson(float a, float b, int n)
{
	float h, x[10], sum = 0;
	int j;
	h = (b - a) / n;
	x[0] = a;
	for (j = 1; j <= n; j++)
	{
		x[j] = a + h * j;
	}

	for (j = 1; j <= n / 2; j++)
	{
		sum += f(x[2 * j - 2]) + 4 * f(x[2 * j - 1]) + f(x[2 * j]);
	}

	return sum * h / 3;
}

int main()
{
	int choose;
	cout << "Task: to implement methods of numerical integration on a user-specified interval." << endl << "Simpson's method." << endl;
	do {
		float a, b;
		int n = 2;
		cout << "\nEnter a value for the left border: ";
		cin >> a;
		cout << endl << "Enter a value for the right border: ";
		cin >> b;
		while (a > b)
		{
			cout << "The left border must be less than the right." << endl << "Enter new value: ";
			cin >> b;
		}
		if (n % 2 == 0)
			cout << endl << "The definite integral value: " << simpson(a, b, n) << endl;
		else
			cout << "Error! " << "The value must be paired." << endl;
		cout << "\nDo you want to start over?" << endl;
		cout << "1) - Yes, 2) - No" << endl;
		cout << "Your choice: ";
		cin >> choose;
	} while (choose == 1);
}