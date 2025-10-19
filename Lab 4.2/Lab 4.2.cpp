// Lab 4.2.cpp 
// < Якимів Наталія > 
// Лабораторна робота № 4.2
// Розгалуження, задане плоскою фігурою.
// Варіант 7
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    double xp, xk, dx;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    const int w1 = 10;   // ширина колонки для x (включно з відступами)
    const int w2 = 18;   // ширина колонки для y

    string border = "+" + string(w1, '-') + "+" + string(w2, '-') + "+";

    cout << fixed;
    cout << border << '\n';
    cout << "|" << setw(w1) << "x" << "|" << setw(w2) << "y" << "|\n";
    cout << border << '\n';

    // прохід по діапазону з урахуванням похибки додавання dx
    for (double x = xp; x <= xk + fabs(dx) / 2.0; x += dx)
    {
        double y;
        if (x <= -5.0)
            y = atan(exp(x));
        else if (x > -5.0 && x <= 0.0)
            y = pow(x, 2) * sin(x / 2.0) + 1.0 + pow(x, 3) / 4.0;
        else // x > 0
            y = log(fabs(x)) - x / 5.0;

        // вивід: для x — 2 знаки після коми, для y — 6 знаків
        cout << "|" << setw(w1) << setprecision(2) << x
            << "|" << setw(w2) << setprecision(6) << y << "|\n";
    }

    cout << border << '\n';
    return 0;
}

