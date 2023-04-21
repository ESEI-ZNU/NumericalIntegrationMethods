#include <cmath>
#include "CalcFunctionArea.h"

double CalcFunctionArea::getValueFunction(double x, int funcType) {
    double a;
    switch (funcType) {
        case 1:
            a = sin(x);
            break;
        case 2:
            a = cos(x);
            break;
        case 3:
            a = exp(x * x);
            break;
        case 4:
            a = cos(x) * sin(x);
            break;
        case 5:
            a = cos(x) * cos(x);
            break;
    }
    return a;
}

double CalcFunctionArea::withoutIntegrate(double a, double b, int n, int funcType) {
    double result;
    switch (funcType) {
        case 1: {
            result = abs(cos(a)-cos(b));
            break;
        }
        case 2: {
            result = abs(sin(a) - sin(b));
            break;
        }
        case 3: {
            result = (sqrt(M_PI) / 2.0) * (erf(sqrt(pow(b, 2)) - erf(sqrt(pow(a, 2)))));
            break;
        }
        case 4: {
            result = abs((1.0 / 2.0) * (sin(pow(b, 2)) - sin(pow(a, 2))));
            break;
        }
        case 5: {
            result = 0.5 * (b - a) + 0.25 * (sin(2.0 * b) - sin(2.0 * a));
            break;
        }
    }
    return result;
}
double CalcFunctionArea::integrateTrapezoidal(double a, double b, int n, int funcType) {
    double h = (b - a) / n;
    double sum = 0.5 * (getValueFunction(a, funcType) + getValueFunction(b, funcType));
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += getValueFunction(x, funcType);
    }
    return h * sum;
}

double CalcFunctionArea::integrateSimpson(double a, double b, int n,int funcType) {
        const double h = (b - a) / n;
        double sum = 0;

        sum = getValueFunction(a, funcType) + getValueFunction(b, funcType);
        for (int i = 1; i <= n-1; i++)
        {
            double x = a + i * h;
            if (i % 2 == 0) {
                sum = sum + 2 * getValueFunction(x, funcType);
            }
            else {
                sum = sum + 4 * getValueFunction(x, funcType);
            }
        }
        sum = sum * (h / 3);
        return (sum);
    }
