#include <iostream>
#include <windows.h>
#include <climits>


using namespace std;
// ����������� ������� ��� ���������� n-�� ����� ������������������ ���������
int task1(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return task1(n - 1) + task1(n - 2);
    }
}

//task2
int binomialCoefficient(int m, int n)
{
    if (m == 0 || m == n)
    {
        return 1;
    }
    else
    {
        return binomialCoefficient(m - 1, n - 1) + binomialCoefficient(m, n - 1);
    }
}


// ������� ��� ���������� ����������
int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        int result = 1;
        for (int i = 2; i <= num; ++i)
        {
            result *= i;
        }
        return result;
    }
}

// ������� ��� ���������� ���������
int binomialCoefficientIterative(int m, int n)
{
    if (m == 0 || m == n)
    {
        return 1;
    }
    else
    {
        return factorial(n) / (factorial(m) * factorial(n - m));
    }
}

//task3
int task3Recursive(int a, int b)
{
    // ������� ������
    if (b == 0)
    {
        return a;
    }

    // ����������� ������
    return task3Recursive(b, a % b);
}

int task3Iterative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


//task4

// ������� ��� ���������� ����� ����� ���� �����
int sumOfCubics(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int digit = n % 10;
        sum += digit * digit * digit;
        n /= 10;
    }
    return sum;
}

// ����������� ������� ��� �������� ���������� � ����� 153
bool checkConvergence(int n, int& iterations)
{
    iterations++;
    int sum = sumOfCubics(n);

    if (sum == 153)
    {
        return true;  // ������������������ �������� � 153
    }
    else
    {
        return checkConvergence(sum, iterations);
    }
}

//task5
int minimum(int a, int b)
{
    if (a == b)
        return a;
    if (a < b)
        return a;
    else
    {
        return b;
    }
}

int minOperationsToOneHundred(int num)
{
    // ������� ������: ���� num ����� 100, �� ����� �������������� ��������
    if (num == 100)
    {
        return 0;
    }

    // �������������� ����������� ���������� �������� ������������ ��������� int
    int minOps = INT_MAX;

    // ����������� ������: �������� �������� 100 ����� "+1" ��� "*2"
    if (num + 1 <= 100)
    {
        int opsPlusOne = minOperationsToOneHundred(num + 1);
        if (opsPlusOne != INT_MAX)
        {
            minOps = minimum(minOps, opsPlusOne + 1);
        }
    }

    if (num * 2 <= 100)
    {
        int opsMulTwo = minOperationsToOneHundred(num * 2);
        if (opsMulTwo != INT_MAX)
        {
            minOps = minimum(minOps, opsMulTwo + 1);
        }
    }

    return minOps;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //task1
    // ������ �������� n
    int n;
    std::cout << "������� �������� n: ";
    std::cin >> n;

    // ������� n-�� ���� ������������������ ���������
    std::cout << "n-�� ���� ������������������ ���������: " << task1(n) << std::endl;


    //task2
    int m;

    // ���� n � m � ����������
    std::cout << "������� n: ";
    std::cin >> n;

    std::cout << "������� m (m ������ ���� ������ ��� ����� n): ";
    std::cin >> m;

    // �������� �� ������������ �����
    if (m > n)
    {
        std::cerr << "������: m ������ ���� ������ ��� ����� n.\n";
        return 1;
    }

    // ����������� ���������� ���������
    int resultRecursive = binomialCoefficient(m, n);
    int resultIterative = binomialCoefficientIterative(m, n);

    std::cout << "����������� ���������: " << resultIterative << std::endl;
    std::cout << "����������� ���������: " << resultRecursive << std::endl;


    //task3
    int a, b;
    cout << "������� a = ";
    cin >> a;
    cout << "������� b = ";
    cin >> b;

    cout << "��� ���������� ��� " << a << " � " << b << " = " << task3Recursive(a, b) << endl;
    cout << "��� ���������� ��� " << a << " � " << b << " = " << task3Iterative(a, b) << endl;

    //task4
    int num;
    std::cout << "������� ����������� �����, ������� 3: ";
    std::cin >> num;

    if (num % 3 != 0 || num <= 0)
    {
        std::cerr << "������: ������� ����������� �����, ������� 3.\n";
        return 1;
    }

    int iterations = 0;

    if (checkConvergence(num, iterations))
    {
        std::cout << "������������������ �������� � ����� 153.\n";
        std::cout << "���������� ��������: " << iterations << std::endl;
    }
    else
    {
        std::cout << "������������������ �� �������� � ����� 153.\n";
    }

    //task5

    int result = minOperationsToOneHundred(1);
    std::cout << "���������� ����� ��������: " << result;

    return 0;
}