// NumericalIntegration.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <functional>

using namespace std;

// Функція для обчислення інтегралу методом прямокутників
double rectangular_integration(double a, double b, int n, function<double(double)> f) {
    double h = (b - a) / n; // Ширина кожного прямокутника
    double sum = 0.0; // Змінна для збереження суми площ прямокутників

    for (int i = 0; i < n; ++i) {
        double x_i = a + i * h; // Ліва границя прямокутника
        double f_i = f(x_i); // Значення функції в точці x_i
        sum += f_i * h; // Додавання площі поточного прямокутника до суми
    }

    return sum;
}

int main() {
    // Введення границь інтегрування та кількості прямокутників
    double a, b;
    int n;
    cout << "Enter the lower limit of integration: ";
    cin >> a;
    cout << "Enter the upper limit of integration: ";
    cin >> b;
    cout << "Enter the number of rectangles: ";
    cin >> n;

    // Введення функції, яку потрібно інтегрувати (наприклад, x^2)
    auto f = [](double x) { return x * x; };

    // Виклик функції для обчислення інтегралу методом прямокутників
    double integral = rectangular_integration(a, b, n, f);

    // Виведення результату
    cout << "The integral of the function over the interval [" << a << ", " << b << "] is: " << integral << endl;

    return 0;
}
