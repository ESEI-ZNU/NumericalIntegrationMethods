// NumericalIntegration.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


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


double f(double x)// функція , яка повертає інтеграл для обчислення
{    
    return x * x * x;// інтеграл для обчислення x^3
}

double metod_trapecii(double c, double d, int n2)// функція для обрахунку методом трапецій
{    
    double h2 = (d - c) / n2;// змінна яка зберігає значення ширини відрізка, яке обчислене за форумлою  
    double sum2 = 0.5 * (f(c) + f(d));  // змінна зберігає остаточну суму, яка обраховує зважену суму за правилом трапецій
    
    for (int i = 1; i < n2; i++)// цикл обчислює значення в кінцях кожного відрізка
    {
        sum2 += f(c + i * h2);
    }
   
    return sum2 * h2; // обчислює заданий інтеграл та повертає його значення
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
    
    double c, d;// оголошення змінних c,d для зберігання нижньої межі та верхньої відповідно
    int n2;// оголошення змінної для зберігання кількості відрізків

    cout << "----------------------------------------------" << endl;
    cout << "We have f(x^3)" << endl;// відображаємо у консоль інтеграл який треба обчислити
    cout << "Enter the lower limit of integration:"; 
    cin >> c;// вводимо значення нижньої межі інтегралу
    cout << "Enter the upper limit of integration: ";
    cin >> d;// вводимо значення для верхньої межі інтегралу
    cout << "Enter the number of line segments: ";
    cin >> n2;// вводимо кількість відрізків
 
    double res = metod_trapecii(c, d, n2); // створюємо змінну , яку ініціалізуємо результатом обчисленного інтегралу
    cout << "Result: " << res << endl; // виводимо результат у консоль
    return 0;
}
