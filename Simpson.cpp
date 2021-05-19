#include<iostream>
#include<cmath>
using namespace std;

double f(double x)
{
	return exp(-x * -x); 
}

double simpsonsRule(double a, double b, int n) {
	double h = 0; 
	double ifx = 0;

	h = abs(b - a) / n;

	ifx = ifx + f(a) + f(b); 

	for (double i = a + h; i < b; i++) {
		ifx = ifx + (4 * f(i));
	}

	for (double j = a + (2 * h); j < b; j++) {
		ifx = ifx + (2 * f(j));
	}

	ifx = ifx * h / 3; //розрахункова формула Сімпсона при інтегруванні на відрізку [a, b]
	return ifx;
}

double mainSimpson() {
	int choose;

	cout << "Task: to implement methods of numerical integration on a user-specified interval." << endl << "Simpson's method." << endl; 
	
	do {
		double a, b; 
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
			cout << endl << "The definite integral value: " << simpsonsRule(a, b, n) << endl;
		else
			cout << "Error! " << "The value must be paired." << endl;
		cout << "\nDo you want to start over?" << endl; 
		cout << "1) - Yes, 2) - No" << endl;
		cout << "Your choice: ";
		cin >> choose;
	} while (choose == 1);

	return choose;
}

int main()
{
	mainSimpson();
}