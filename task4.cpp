#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <Windows.h>

using namespace std;

// ������� ��� ���������� ������� �� �����
vector<int> readArrayFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "������ �������� �����." << endl;
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

// ������� ��� ������ �������
void printArray(const vector<int>& arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// ������� ��� ������ ������� ���������� � ���������� ���������� ������� ������
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

    cout << "����� ������:" << endl;
    cout << "���������� �������� ���������: " << comparisons << endl;
    cout << "���������� �������� ���������: " << swaps << endl;
    cout << "����� ����������: " << duration.count()/1000. << " �" << endl;
}

// ������� ��� ������ ������� ���������� � ���������� ���������� ������� �������
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

    cout << "����� �������:" << endl;
    cout << "���������� �������� ���������: " << comparisons << endl;
    cout << "���������� �������� ���������: " << swaps << endl;
    cout << "����� ����������: " << duration.count()/1000. << " �" << endl;
}

// ������� ��� ������ ������� ���������� � ���������� ���������� ������� ������ (���������)
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

    cout << "����� ������ (���������):" << endl;
    cout << "���������� �������� ���������: " << comparisons << endl;
    cout << "���������� �������� ���������: " << swaps << endl;
    cout << "����� ����������: " << duration.count() / 1000. << " �" << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const string filename = "input.txt"; // ��� ����� � �������� �������
    vector<int> arr = readArrayFromFile(filename);

    int comparisons = 0; // ���������� �������� ���������
    int swaps = 0; // ���������� �������� ���������

    // ����� ������
    vector<int> arrSelection = arr; // ������� ����� ������� ��� ������� ������
    selectionSort(arrSelection, comparisons, swaps);
    cout << "��������������� ������ ������� ������: ";
    printArray(arrSelection);
    cout << endl;

    // ����� �������
    comparisons = 0; // ���������� ��������
    swaps = 0;
    vector<int> arrInsertion = arr; // ������� ����� ������� ��� ������� ������
    insertionSort(arrInsertion, comparisons, swaps);
    cout << "��������������� ������ ������� �������: ";
    printArray(arrInsertion);
    cout << endl;

    // ����� ������ (���������)
    comparisons = 0; // ���������� ��������
    swaps = 0;
    vector<int> arrBubble = arr; // ������� ����� ������� ��� ������� ������
    bubbleSort(arrBubble, comparisons, swaps);
    cout << "��������������� ������ ������� ������ (���������): ";
    printArray(arrBubble);

    return 0;
}
