#include <iostream>
#include <cmath>
#define f(x) exp(-x*-x)
using namespace std;

int main()
{
link:int chooserepit, choosemethod;


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
