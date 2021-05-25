
#include<iostream>
#include<cmath>

#define f(x) exp(-x*-x)

using namespace std;

void mainSimpson() {

        int n;
        float a, b;
        cout << "\nEnter lower limit of integration: ";
        cin >> a;
        cout << "Enter upper limit of integration: ";
        cin >> b;
        cout << "Enter number of sub intervals: ";
        cin >> n;
   
        const double width = (b-a)/n;

        double simpson_integral = 0;
        for(int step = 0; step < n; step++) {
            const double x1 = a + step*width;
            const double x2 = a + (step+1)*width;

            simpson_integral += (x2-x1)/6.0*(f(x1) + 4.0*f(0.5*(x1+x2)) + f(x2));
        }

        cout << "\nIntegration = " <<  simpson_integral << endl;
    }
