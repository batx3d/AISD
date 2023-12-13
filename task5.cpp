#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

// ������� ��� ���������� ������� �� �����
vector<double> readArrayFromFile(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "������ �������� �����." << endl;
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

// ������� ��� ������ ������� � ����
void writeArrayToFile(const string& filename, const vector<double>& arr)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cerr << "������ �������� ����� ��� ������." << endl;
        exit(EXIT_FAILURE);
    }

    for (double num : arr)
    {
        file << num << " ";
    }

    file.close();
}

// ������� ��� ������ �������
void printArray(const vector<double>& arr)
{
    for (double num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// ������� ��� ������ ������� ���������� � ���������� ���������� ������� ������
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

// ������� ��� ������ ������� ���������� � ���������� ���������� ������� �������
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

// ������� ��� ������ ������� ���������� � ���������� ���������� ������� ������ (���������)
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

// ������� ��� ��������� ������
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
            cout << "������� " << target << " ������ �� ������� " << mid << "." << endl;
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

    cout << "������� " << target << " �� ������." << endl;
    return comparisons;
}

// ������� ��� ��������� ������
int linearSearch(const vector<double>& arr, double target)
{
    int comparisons = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        comparisons++;
        if (arr[i] == target)
        {
            cout << "������� " << target << " ������ �� ������� " << i << "." << endl;
            return comparisons;
        }
    }
    cout << "������� " << target << " �� ������." << endl;
    return comparisons;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    const string inputFilename = "input.txt"; // ��� ����� � �������� �������
    const string outputFilename = "output.txt"; // ��� ����� ��� ������ ��������������� ������

    // ��������� ������ �� �����
    vector<double> arr = readArrayFromFile(inputFilename);

    // �������� ������ ��� ������� ������ ����������
    vector<double> arrSelection = arr;
    vector<double> arrInsertion = arr;
    vector<double> arrBubble = arr;

    // ���������� ������� ������
    int comparisonsSelection = selectionSort(arrSelection);
    cout << "������ ����� ���������� �������:" << endl;
    printArray(arrSelection);
    cout << "���������� �������� ��������� (�����): " << comparisonsSelection << endl << endl;

    // ���������� ������� �������
    int comparisonsInsertion = insertionSort(arrInsertion);
    cout << "������ ����� ���������� ���������:" << endl;
    printArray(arrInsertion);
    cout << "���������� �������� ��������� (�������): " << comparisonsInsertion << endl << endl;

    // ���������� ������� ������ (���������)
    int comparisonsBubble = bubbleSort(arrBubble);
    cout << "������ ����� ���������� ������� (���������):" << endl;
    printArray(arrBubble);
    cout << "���������� �������� ��������� (�����): " << comparisonsBubble << endl << endl;

    // ��������� ��������������� ������ � ����� ����
    writeArrayToFile(outputFilename, arrBubble);

    // �������� �����
    double targetBinary = 35; // �������, ������� ����� ������
    int comparisonsBinary = binarySearch(arrBubble, targetBinary);
    cout << "���������� �������� ��������� (�������� �����): " << comparisonsBinary;
}
