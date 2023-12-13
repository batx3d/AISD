#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

// Функция для считывания массива из файла
vector<double> readArrayFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Ошибка открытия файла." << endl;
        exit(EXIT_FAILURE);
    }

    vector<double> arr;
    double num;
    while (file >> num)
    {
        arr.push_back(num);
    }

    file.close();
    return arr;
}

// Функция для записи массива в файл
void writeArrayToFile(const string& filename, const vector<double>& arr)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cerr << "Ошибка открытия файла для записи." << endl;
        exit(EXIT_FAILURE);
    }

    for (double num : arr)
    {
        file << num << " ";
    }

    file.close();
}

// Функция для вывода массива
void printArray(const vector<double>& arr)
{
    for (double num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Функция для замера времени выполнения и выполнения сортировки методом выбора
int selectionSort(vector<double>& arr)
{
    int comparisons = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            comparisons++;
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
    return comparisons;
}

// Функция для замера времени выполнения и выполнения сортировки методом вставок
int insertionSort(vector<double>& arr)
{
    int comparisons = 0;
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        double key = arr[i];
        int j = i - 1;

        comparisons++;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
    return comparisons;
}

// Функция для замера времени выполнения и выполнения сортировки методом обмена (пузырьком)
int bubbleSort(vector<double>& arr)
{
    int comparisons = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return comparisons;
}

// Функция для бинарного поиска
int binarySearch(const vector<double>& arr, double target)
{
    int left = 0;
    int right = arr.size() - 1;
    int comparisons = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == target)
        {
            cout << "Элемент " << target << " найден на позиции " << mid << "." << endl;
            return comparisons;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << "Элемент " << target << " не найден." << endl;
    return comparisons;
}

// Функция для сквозного поиска
int linearSearch(const vector<double>& arr, double target)
{
    int comparisons = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        comparisons++;
        if (arr[i] == target)
        {
            cout << "Элемент " << target << " найден на позиции " << i << "." << endl;
            return comparisons;
        }
    }
    cout << "Элемент " << target << " не найден." << endl;
    return comparisons;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    const string inputFilename = "input.txt"; // Имя файла с входными данными
    const string outputFilename = "output.txt"; // Имя файла для записи отсортированных данных

    // Считываем массив из файла
    vector<double> arr = readArrayFromFile(inputFilename);

    // Копируем массив для каждого метода сортировки
    vector<double> arrSelection = arr;
    vector<double> arrInsertion = arr;
    vector<double> arrBubble = arr;

    // Сортировка методом выбора
    int comparisonsSelection = selectionSort(arrSelection);
    cout << "Массив после сортировки выбором:" << endl;
    printArray(arrSelection);
    cout << "Количество операций сравнения (выбор): " << comparisonsSelection << endl << endl;

    // Сортировка методом вставок
    int comparisonsInsertion = insertionSort(arrInsertion);
    cout << "Массив после сортировки вставками:" << endl;
    printArray(arrInsertion);
    cout << "Количество операций сравнения (вставки): " << comparisonsInsertion << endl << endl;

    // Сортировка методом обмена (пузырьком)
    int comparisonsBubble = bubbleSort(arrBubble);
    cout << "Массив после сортировки обменом (пузырьком):" << endl;
    printArray(arrBubble);
    cout << "Количество операций сравнения (обмен): " << comparisonsBubble << endl << endl;

    // Сохраняем отсортированный массив в новый файл
    writeArrayToFile(outputFilename, arrBubble);

    // Бинарный поиск
    double targetBinary = 35; // Элемент, который будем искать
    int comparisonsBinary = binarySearch(arrBubble, targetBinary);
    cout << "Количество операций сравнения (бинарный поиск): " << comparisonsBinary;
}
