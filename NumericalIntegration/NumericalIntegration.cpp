﻿// NumericalIntegration.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream> // Бібліотека введення виведення
#include <Windows.h> // бібліотека для роботи з Windows

using namespace std; // Використання простору імен std

/// <summary>
/// класс методу трапецій
/// @author Kuzmenko
/// </summary>
class trapecia
{
public:
       /// <summary>
       /// функція , яка повертає інтеграл для обчислення
       /// </summary>
	double f_2(double x)// функція , яка повертає інтеграл для обчислення
	{
		return x * x;// інтеграл для обчислення
	}
	/// <summary>
	/// функція яка обчислює х^2
	/// @author Kuzmenko
	/// </summary>
	/// <param name="c">
	/// значення нижньої межі інтегралу
	/// </param>
	/// <param name="d">
	/// значення для верхньої межі інтегралу
	/// </param>
	/// <param name="n_2">
	/// кількість відрізків
	/// </param>
	double metod_trapecii_2(double c, double d, int n_2)// функція для обрахунку методом трапецій x^2
	{
		double h_2 = (d - c) / n_2;// змінна яка зберігає значення ширини відрізка, яке обчислене за форумлою 
		double sum_2 = 0.5 * (f_2(c)) + (f_2(d));// змінна зберігає остаточну суму, яка обраховує зважену суму за правилом трапецій

		for (int i = 1; i < n_2; i++)// цикл обчислює значення в кінцях кожного відрізка
		{
			sum_2 += f_2(c + i * h_2);
		}

		return sum_2 * h_2;// обчислює заданий інтеграл та повертає його значення
	}
        /// <summary>
        /// функція , яка повертає інтеграл для обчислення
        /// </summary>
	double f_3(double x)
	{
		return x * x * x;
	}
	/// <summary>
	/// функція яка обчислює х^3
	/// @author Kuzmenko
	/// </summary>
	/// <param name="c">
	/// значення нижньої межі інтегралу
	/// </param>
	/// <param name="d">
	/// значення для верхньої межі інтегралу
	/// </param>
	/// <param name="n_2">
	/// кількість відрізків
	/// </param>
	double metod_trapecii_3(double c, double d, int n_2)// функція для обрахунку методом трапецій x^3
	{
		double h_2 = (d - c) / n_2;// змінна яка зберігає значення ширини відрізка, яке обчислене за форумлою 
		double sum_2 = 0.5 * (f_3(c)) + (f_3(d));// змінна зберігає остаточну суму, яка обраховує зважену суму за правилом трапецій

		for (int i = 1; i < n_2; i++)// цикл обчислює значення в кінцях кожного відрізка
		{
			sum_2 += f_3(c + i * h_2);
		}

		return sum_2 * h_2;// обчислює заданий інтеграл та повертає його значення
	}
};
/// <summary>
/// функція взаємодії з користувачем
/// @author Kuzmenko Pyatnitsky
/// </summary>
void user(int metod, int function, double c , double d, double res, int n_2) 
{
	trapecia t;

	cout << "|Оберіть метод обчислення інтегралa|" << endl;
	cout << " Метод прямокутників - 1" << endl;
	cout << " Метод трапецій - 2" << endl;
	cout << " Введіть номер методу: ";
	cin >> metod;

	cout << "----------------------------------------" << endl;

	cout << "|Оберіть функцію для інтегрування|" << endl;
	cout << " x^2 - перший (1)" << endl;
	cout << " x^3 - другий (2)" << endl;
	cout << " Введіть номер функції: ";
	cin >> function;


	if (metod == 2)//якщо метод трапецій то f(x^2) або f(x^3)
	{
		if (function == 1)
		{
			cout << "----------------------------------------" << endl;
			cout << "Маємо функцію f(x^2)" << endl;// відображаємо у консоль інтеграл який треба обчислити
			cout << "Введіть нижню границю:";
			cin >> c;// вводимо значення нижньої межі інтегралу
			cout << "Введіть верхню границю: ";
			cin >> d;// вводимо значення для верхньої межі інтегралу
			cout << "Введіть кількість відрізків: ";
			cin >> n_2;// вводимо кількість відрізків

			res = t.metod_trapecii_2(c, d, n_2); //виклик функції f(x^2)
			cout << "Відповідь: " << res << endl;
		}
		else if (function == 2)
		{
			cout << "----------------------------------------" << endl;
			cout << "Маємо функцію f(x^3)" << endl;// відображаємо у консоль інтеграл який треба обчислити
			cout << "Введіть нижню границю:";
			cin >> c;// вводимо значення нижньої межі інтегралу
			cout << "Введіть верхню границю: ";
			cin >> d;// вводимо значення для верхньої межі інтегралу
			cout << "Введіть кількість відрізків: ";
			cin >> n_2;// вводимо кількість відрізків

			res = t.metod_trapecii_3(c, d, n_2);//виклик функції f(x^3)
			cout << "Відповідь: " << res << endl;
		}
	}
}

/// основна функція 
/// @author Kuzmenko Pyatnitsky 
int main() 
{
SetConsoleCP(1251);//встановлення кодування українських символів
SetConsoleOutputCP(1251);//встановлення кодування українських символів

int metod, function;// змінні для зберігання вибору користувача
double c, d, res;// оголошення змінних c,d для зберігання нижньої межі та верхньої та результату
int n_2;// оголошення змінної для зберігання кількості відрізків

user( metod, function, c, d, res, n_2 );// виклик функції , яка взаємодіє з користувачем
}
