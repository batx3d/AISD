#include <iostream>
#include <fstream>
#include <Windows.h>
#include <math.h>
#include <stdio.h>
#include <ctime>

using namespace std;

double f(double x)
{
    return pow(x, 3) - x + exp(-x);
}

double goldenRatio(double a, double b, double eps, ofstream& outFile)
{
    if (a > b)
    {
        swap(a, b);
    }
    double x1, x2;
    const double Phi = (1 + sqrt(5)) / 2.;
    int iterations = 0;
    while (abs(b - a) > eps)
    {
        x1 = b - ((b - a) / Phi);
        x2 = a + ((b - a) / Phi);
        if (f(x1) >= f(x2))
        {
            a = x1;
            outFile << iterations << ". x = " << a << " " << "y = " << f(x1) << endl;
            cout << iterations << ". x = " << a << " " << "y = " << f(x1) << endl;
        }
        else
        {
            b = x2;
            outFile << iterations << ". x = " << b << " " << "y = " << f(x2) << endl;
            cout << iterations << ". x = " << b << " " << "y = " << f(x2) << endl;
        }

        iterations++;
    }
    outFile << "\n\n���������� �����: " << iterations << endl;
    return (a + b) / 2.;
}

int main()
{
    srand(time(0)); // ��������� �����
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a, b;
    double eps;
    cout << "������� a = ";
    cin >> a;
    cout << "������� b = ";
    cin >> b;
    cout << "������� eps = ";
    cin >> eps;
    const char* filename = "task2.txt";

    ofstream outFile(filename);

    if (!outFile.is_open())
    {
        cerr << "������ �������� �����!" << endl;
        return 1;
    }

    double min = goldenRatio(a, b, eps, outFile);

    cout << "����������� �������� ������� �� [" << a << " , " << b << "] = " << min << endl;
    cout << "������� ��������� � ����� � = " << min << " Y = " << f(min) << endl;
    cout << "����� ������ ��������� = " << clock() / 1000.0 << endl;
    outFile << "����������� �������� ������� �� [" << a << " , " << b << "] = " << min << endl;
    outFile << "������� ��������� � ����� � = " << min << " Y = " << f(min) << endl;
    outFile << "����� ������ ��������� = " << clock() / 1000.0 << endl;

    outFile.close();

    return 0;
}
