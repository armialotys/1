#include <iostream>
#include <cmath>
using namespace std;

double D(double a, double b, double c) { // функция дискриминанта , D - функция дискриминанта
	double d;
	d =  b * b - 4 * a * c; // дискриминант
	return d;
}

int rootsCount(double d) { // функция для подсчёта количество корней
	int rootsCount;
	if (d < 0) {
		rootsCount = 0;
	}
	else if (d == 0) {
		rootsCount = 1;
	}
	else {
		rootsCount = 2;
	}
	return rootsCount;
}

double solveLinearEquation(double b, double c) { // функция для решения линейного уравнения
	return -c / b;
}

double firstRoot(double b, double d, double a) { // функция для 1 корня
	return (-b + sqrt(d)) / (2 * a);
}

double secondRoot(double b, double d, double a) { // фунция для 2 корня
	return (-b - sqrt(d)) / (2 * a);
}

int main() {
	double a, b, c, x1, x2, d; // создаются переменные
	int roots;
	char choice = 'y';
	while (choice == 'y') {
		cin >> a >> b >> c; // вводятся переменные через консоль
		if (a == 0) {
			cout << " Type : linear equation \n x = " << solveLinearEquation(b, c) << endl;
		}
		else {
			d = D(a, b, c); // D
			roots = rootsCount(d);
			cout << roots << " root(s) " << endl;
			if (roots == 1) { // проверка на дискриминант = 0
				x1 = -b / (2 * a);
				cout << x1 << endl;
			}
			else if (roots == 2) { // проверка на дискриминант > 0
				x1 = firstRoot(b, d, a);
				x2 = secondRoot(b, d, a);
				cout << x1 << " , " << x2 << endl;
			}
		}
		cout << " Continue? (y / n) " << endl;
		cin >> choice;
	}
	cout << " Bye " << endl;
	return 0;
}
