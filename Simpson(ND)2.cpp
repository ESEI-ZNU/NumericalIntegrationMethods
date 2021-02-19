#include <math.h>
#include <iostream>
using namespace std;
float Integ(float x)
{
    return exp(-x * -x);
}

float Func(int n, float a, float b)
{
    int i = 1;
    float sum = 0, h;
    h = (b - a) / (2 * n);
    for (i = 1; i <= (2 * n - 1); i++)
        sum += (3 + pow(-1, i + 1)) * Integ(a + i * h);
    return h / 3 * (Integ(a) + Integ(b) + sum);
}
int main()
{
    int choose;
    cout << "Task: to implement methods of numerical integration on a user-specified interval." << endl << "Simpson's method." << endl;
    do {
        float a, b, e = 0.0001;
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
        while (fabs(Func(4 * n, a, b) - Func(2 * n, a, b)) >= e)
        {
            n *= 2;
        }
        cout << endl << "The definite integral value: " << Func(4 * n, a, b);
        cout << endl << "\nDo you want to start over?" << endl;
        cout << "1) - Yes, 2) - No" << endl;
        cout << "Your choice: ";
        cin >> choose;
    } while (choose == 1);
}