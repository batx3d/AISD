#include <iostream>
#include <windows.h>
#include <climits>


using namespace std;
// Рекурсивная функция для нахождения n-го члена последовательности Фибоначчи
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


// Функция для вычисления факториала
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

// Функция для вычисления сочетаний
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
    // Базовый случай
    if (b == 0)
    {
        return a;
    }

    // Рекурсивный случай
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

// Функция для вычисления суммы кубов цифр числа
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

// Рекурсивная функция для проверки сходимости к числу 153
bool checkConvergence(int n, int& iterations)
{
    iterations++;
    int sum = sumOfCubics(n);

    if (sum == 153)
    {
        return true;  // последовательность сходится к 153
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
    // Базовый случай: если num равно 100, не нужны дополнительные операции
    if (num == 100)
    {
        return 0;
    }

    // Инициализируем минимальное количество операций максимальным значением int
    int minOps = INT_MAX;

    // Рекурсивный случай: пытаемся получить 100 через "+1" или "*2"
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
    // Задаем значение n
    int n;
    std::cout << "Введите значение n: ";
    std::cin >> n;

    // Выводим n-ый член последовательности Фибоначчи
    std::cout << "n-ый член последовательности Фибоначчи: " << task1(n) << std::endl;


    //task2
    int m;

    // Ввод n и m с клавиатуры
    std::cout << "Введите n: ";
    std::cin >> n;

    std::cout << "Введите m (m должно быть меньше или равно n): ";
    std::cin >> m;

    // Проверка на корректность ввода
    if (m > n)
    {
        std::cerr << "Ошибка: m должно быть меньше или равно n.\n";
        return 1;
    }

    // Рекурсивное вычисление сочетаний
    int resultRecursive = binomialCoefficient(m, n);
    int resultIterative = binomialCoefficientIterative(m, n);

    std::cout << "Итеративный результат: " << resultIterative << std::endl;
    std::cout << "Рекурсивный результат: " << resultRecursive << std::endl;


    //task3
    int a, b;
    cout << "Введите a = ";
    cin >> a;
    cout << "Введите b = ";
    cin >> b;

    cout << "НОД рекурсивно для " << a << " и " << b << " = " << task3Recursive(a, b) << endl;
    cout << "НОД итеративно для " << a << " и " << b << " = " << task3Iterative(a, b) << endl;

    //task4
    int num;
    std::cout << "Введите натуральное число, кратное 3: ";
    std::cin >> num;

    if (num % 3 != 0 || num <= 0)
    {
        std::cerr << "Ошибка: Введите натуральное число, кратное 3.\n";
        return 1;
    }

    int iterations = 0;

    if (checkConvergence(num, iterations))
    {
        std::cout << "Последовательность сходится к числу 153.\n";
        std::cout << "Количество итераций: " << iterations << std::endl;
    }
    else
    {
        std::cout << "Последовательность не сходится к числу 153.\n";
    }

    //task5

    int result = minOperationsToOneHundred(1);
    std::cout << "Наименьшое число операций: " << result;

    return 0;
}