#include <iostream>
#include <cmath>
#include <ctime>
#define f(x) exp(-x*-x)
using namespace std;


// Rectangles Method
double rect_integ(float a, float b, int n)
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


void mainRectangles()
{
	float a, b;
	int n;
	cout << "Lower limit of integration a = ";
	cin >> a;
	cout << "Upper limit of integration b = ";
	cin >> b;
	cout << "Number of subintervals n = ";
	cin >> n;
	cout << "Integral is equal to: " << rect_integ(a, b, n) << endl;
}

// Trapezium Method
void mainTrapezium()
{
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

	cout << endl << "Integration = " << integration << endl;
}

// Simpson Method
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

void mainSimpson() {
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
}


int main()
{
link:int chooserepit, choosemethod;
	double timeInSeconds;


	cout << "	IntegrationMethods\n" << endl;
	cout << " 1) Method of Rectangles\n";
	cout << " 2) Method of Trapezium \n";
	cout << " 3) Method of Simpson\n" << endl;
uncorrect: cout << " Your chose: ";
	cin >> choosemethod;
	cout << endl << endl;
	if (choosemethod == 1)
	{
		cout << "	Method of Rectangles\n" << endl << endl;
		clock_t startTime = clock();
		mainRectangles();
		clock_t endTime = clock();
		clock_t clockTicksTaken = endTime - startTime;
		timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
		cout << "Execution of this method took " << timeInSeconds << " seconds" << endl << endl;
	}

	else if (choosemethod == 2)
	{
		cout << "	Method of Trapezium\n" << endl << endl;
		clock_t startTime = clock();
		mainTrapezium();
		clock_t endTime = clock();
		clock_t clockTicksTaken = endTime - startTime;
		timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
		cout << "Execution of this method took " << timeInSeconds << " seconds" << endl << endl;
	}

	else if (choosemethod == 3)
	{
		cout << "	Method of Simpson\n" << endl << endl;
		clock_t startTime = clock();
		mainSimpson();
		clock_t endTime = clock();
		clock_t clockTicksTaken = endTime - startTime;
		timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
		cout << "Execution of this method took " << timeInSeconds << " seconds" << endl << endl;
	}

	else
	{
		cout << " Choose the correct option\n" << endl << endl;
		goto uncorrect;
	}


	cout << " Start over?" << endl << endl
		<< " 1 - Yes" << endl
		<< " 2 - No" << endl << endl
		<< " Your chose: ";
	cin >> chooserepit;
	cout << endl << endl;
	if (chooserepit == 1) {
		cout << endl;
		goto link;
	}
	else
	{
		cout << " You have chosen to end work with the program\n" << endl << endl;
		system("pause");
	}
}