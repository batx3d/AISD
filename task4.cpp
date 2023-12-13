#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <Windows.h>

using namespace std;

// Функция для считывания массива из файла
vector<int> readArrayFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Ошибка открытия файла." << endl;
        exit(EXIT_FAILURE);
    }

    vector<int> arr;
    int num;
    while (file >> num)
    {
        arr.push_back(num);
    }

    file.close();
    return arr;
}

// Функция для вывода массива
void printArray(const vector<int>& arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Функция для замера времени выполнения и выполнения сортировки методом выбора
void selectionSort(vector<int>& arr, int& comparisons, int& swaps)
{
    auto start_time = chrono::high_resolution_clock::now();

    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int max_index = i;
        for (int j = i + 1; j < n; ++j)
        {
            comparisons++;
            if (arr[j] > arr[max_index])
            {
                max_index = j;
            }
        }

        swaps++;
        swap(arr[i], arr[max_index]);
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Метод выбора:" << endl;
    cout << "Количество операций сравнения: " << comparisons << endl;
    cout << "Количество операций пересылки: " << swaps << endl;
    cout << "Время выполнения: " << duration.count()/1000. << " с" << endl;
}

// Функция для замера времени выполнения и выполнения сортировки методом вставок
void insertionSort(vector<int>& arr, int& comparisons, int& swaps)
{
    auto start_time = chrono::high_resolution_clock::now();

    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        comparisons++;
        while (j >= 0 && arr[j] < key)
        {
            swaps++;
            arr[j + 1] = arr[j];
            j--;
        }

        swaps++;
        arr[j + 1] = key;
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Метод вставок:" << endl;
    cout << "Количество операций сравнения: " << comparisons << endl;
    cout << "Количество операций пересылки: " << swaps << endl;
    cout << "Время выполнения: " << duration.count()/1000. << " с" << endl;
}

// Функция для замера времени выполнения и выполнения сортировки методом обмена (пузырьком)
void bubbleSort(vector<int>& arr, int& comparisons, int& swaps)
{
    auto start_time = chrono::high_resolution_clock::now();

    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            comparisons++;
            if (arr[j] < arr[j + 1])
            {
                swaps++;
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Метод обмена (пузырьком):" << endl;
    cout << "Количество операций сравнения: " << comparisons << endl;
    cout << "Количество операций пересылки: " << swaps << endl;
    cout << "Время выполнения: " << duration.count() / 1000. << " с" << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const string filename = "input.txt"; // Имя файла с входными данными
    vector<int> arr = readArrayFromFile(filename);

    int comparisons = 0; // Количество операций сравнения
    int swaps = 0; // Количество операций пересылки

    // Метод выбора
    vector<int> arrSelection = arr; // Создаем копию массива для каждого метода
    selectionSort(arrSelection, comparisons, swaps);
    cout << "Отсортированный массив методом выбора: ";
    printArray(arrSelection);
    cout << endl;

    // Метод вставок
    comparisons = 0; // Сбрасываем счетчики
    swaps = 0;
    vector<int> arrInsertion = arr; // Создаем копию массива для каждого метода
    insertionSort(arrInsertion, comparisons, swaps);
    cout << "Отсортированный массив методом вставок: ";
    printArray(arrInsertion);
    cout << endl;

    // Метод обмена (пузырьком)
    comparisons = 0; // Сбрасываем счетчики
    swaps = 0;
    vector<int> arrBubble = arr; // Создаем копию массива для каждого метода
    bubbleSort(arrBubble, comparisons, swaps);
    cout << "Отсортированный массив методом обмена (пузырьком): ";
    printArray(arrBubble);

    return 0;
}
