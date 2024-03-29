// NumericalIntegration.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream> // Бібліотека введення виведення
#include <functional> // Включення бібліотеки для функцій

using namespace std; // Використання простору імен std

// Функція для обчислення інтегралу методом прямокутників
double rectangular_integration(double a, double b, int n, function<double(double)> f) {
    double h = (b - a) / n; // Ширина кожного прямокутника
    double sum = 0.0; // Змінна для збереження суми площ прямокутників

    for (int i = 0; i < n; ++i) { // Цикл для кожного прямокутника
        double x_i = a + i * h; // Ліва границя прямокутника
        double f_i = f(x_i); // Значення функції в точці x_i
        sum += f_i * h; // Додавання площі поточного прямокутника до суми
    }

    return sum; // Повернення значення інтегралу
}

int main() {
    // Введення границь інтегрування та кількості прямокутників
    double a, b;
    int n;
    cout << "Enter the lower limit of integration: ";// Виведення тексту
    cin >> a;// Зчитування нижньої границі
    cout << "Enter the upper limit of integration: ";// Виведення тексту
    cin >> b;// Зчитування верхньої границі
    cout << "Enter the number of rectangles: ";// Виведення тексту
    cin >> n;// Зчитування кількості прямокутників

    // Введення функції, яку потрібно інтегрувати (наприклад, x^2)
    auto f = [](double x) { return x * x; };// Функція x^2

    // Виклик функції для обчислення інтегралу методом прямокутників
    double integral = rectangular_integration(a, b, n, f);// Обчислення інтегралу

    // Виведення результату
    cout << "The integral of the function over the interval [" << a << ", " << b << "] is: " << integral << endl;// Виведення інтегралу

    return 0;
}
