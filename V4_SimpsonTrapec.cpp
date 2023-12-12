#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double Trapec_M(double(*f)(double), double a, double b, double E);
double Simpson_M(double(*f)(double), double a, double b, double E);

double integral_1(double x)
{
	return (1 + x * x) / (1 + x * x * x);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	double(*P[1])(double x) = { integral_1 };

	double ab[1][2];
	ab[0][0] = 3;	ab[0][1] = 4.254;

	int number = 1;
	cout << "\n Функция (1+x^2)/(1+x^3): \n";
	cout << "Метод трапеции при epsilon = 1e-4: " << endl;
	double integral = Trapec_M(*(P[number - 1]), ab[number - 1][0], ab[number - 1][1], 1e-4);
	cout << "Метод трапеции при epsilon = 1e-5: " << endl;
	integral = Trapec_M(*(P[number - 1]), ab[number - 1][0], ab[number - 1][1], 1e-5);
	cout << "Метод Симпсона при epsilon = 1e-4: " << endl;
	integral = Simpson_M(*(P[number - 1]), ab[number - 1][0], ab[number - 1][1], 1e-4);
	cout << "Метод Симпсона при epsilon = 1e-5: " << endl;
	integral = Simpson_M(*(P[number - 1]), ab[number - 1][0], ab[number - 1][1], 1e-5);

	system("pause");
	return 0;
}

double Trapec_M(double (*f)(double), double a, double b, double E)
{

	int n = 2;
	double x = a;
	double h = (b - a) / n;
	double I_h = (f(a) + f(b)) / 2;
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		x += h;
		I_h += f(x);
	}
	I_h *= h;
	k++;
	cout << "k= " << k << setw(10) << "h= " << h << setw(10) << "I= " << I_h << endl;

	n = 4;
	x = a;
	h = (b - a) / n;
	double I_h2 = (f(a) + f(b)) / 2;
	for (int i = 1; i < n; i++)
	{
		x += h;
		I_h2 += f(x);
	}
	I_h2 *= h;
	k++;
	cout << "k= " << k << setw(10) << "h= " << h << setw(15) << "I= " << I_h2 << endl;
	while (abs(I_h2 - I_h) > 3 * E)
	{
		I_h = I_h2;
		x = a;
		n *= 2;
		h = (b - a) / n;
		I_h2 = (f(a) + f(b)) / 2;
		for (int i = 1; i < n; i++)
		{
			x += h;
			I_h2 += f(x);
		}
		I_h2 *= h;
		k++;
		cout << "k= " << k << setw(10) << "h= " << h << setw(15) << "I= " << I_h2 << endl;
	}
	return I_h2;
}
double Simpson_M(double(*f)(double), double a, double b, double E)
{

	int n = 1;
	double x = a;
	double h = (b - a) / (2 * n);
	double I_h = f(x);
	int k = 0;
	for (int i = 1; i < 2 * n; i++)
	{
		x += h;
		if (i % 2 == 0)
		{
			I_h += 2 * f(x);
		}
		else
		{
			I_h += 4 * f(x);
		}
	}
	x += h;
	I_h += f(x);
	I_h *= h / 3;
	k++;
	cout << "k= " << k << setw(10) << "h= " << h << setw(10) << "I= " << I_h << endl;

	n = 2;
	x = a;
	h = (b - a) / (2 * n);
	double I_h2 = f(x);
	for (int i = 1; i < 2 * n; i++)
	{
		x += h;
		if (i % 2 == 0)
		{
			I_h2 += 2 * f(x);
		}
		else
		{
			I_h2 += 4 * f(x);
		}
	}
	x += h;
	I_h2 += f(x);
	I_h2 *= h / 3;
	k++;
	cout << "k= " << k << setw(10) << "h= " << h << setw(10) << "I= " << I_h2 << endl;
	while (abs(I_h2 - I_h) > 15 * E)
	{
		I_h = I_h2;
		n *= 2;
		x = a;
		h = (b - a) / (2 * n);
		I_h2 = f(x);
		for (int i = 1; i < 2 * n; i++)
		{
			x += h;
			if (i % 2 == 0)
			{
				I_h2 += 2 * f(x);
			}
			else
			{
				I_h2 += 4 * f(x);
			}
		}
		x += h;
		I_h2 += f(x);
		I_h2 *= h / 3;
		k++;
		cout << "k= " << k << setw(10) << "h= " << h << setw(10) << "I= " << I_h2 << endl;
	}
	return I_h2;
}


