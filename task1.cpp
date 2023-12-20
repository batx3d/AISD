#include <iostream>
#include <fstream>
using namespace std;


struct Matrix {
    int size = 0;
    double** matrix = NULL;
};

Matrix ReadMatrixFromFile(const char* fileName)
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        cerr << "Unable to open file." << endl;
    }

    Matrix result;

    int value = 0;

    while (file >> value)
    {
        result.size++;
    }
    result.size = sqrt(result.size);

    result.matrix = new double*[result.size];

    for (int i = 0; i < result.size; i++)
    {
        result.matrix[i] = new double[result.size];
    }

    //read from matrix
    file.clear();
    file.seekg(0, std::ios::beg);

    for (int  i = 0; i < result.size; i++)
    {
        for (int j = 0; j < result.size; j++)
        {
            file >> result.matrix[i][j];
        }
    }

    file.close();
    return result;
}

void printMatrix(Matrix& matrix)
{
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < matrix.size; j++)
        {
            std::cout << matrix.matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix GaussJordan(Matrix& matrix)
{
    int n = matrix.size;

    // Создаем единичную матрицу
    double** EyeMatrix = new double* [n];
    for (int i = 0; i < n; i++)
    {
        EyeMatrix[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            EyeMatrix[i][j] = (i == j) ? 1 : 0;
        }
    }

    // Создаем общую матрицу
    double** SupplemenMatrix = new double* [n];
    for (int i = 0; i < n; i++)
    {
        SupplemenMatrix[i] = new double[2 * n];
        for (int j = 0; j < n; j++)
        {
            SupplemenMatrix[i][j] = matrix.matrix[i][j];
            SupplemenMatrix[i][j + n] = EyeMatrix[i][j];
        }
    }

    // Прямой ход (Зануление нижнего левого угла)
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < 2 * n; i++)
        {
            SupplemenMatrix[k][i] = SupplemenMatrix[k][i] / matrix.matrix[k][k];
        }
        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                double K = SupplemenMatrix[i][k] / SupplemenMatrix[k][k];
                for (int j = 0; j < 2 * n; j++)
                {
                    SupplemenMatrix[i][j] = SupplemenMatrix[i][j] - SupplemenMatrix[k][j] * K;
                }
            }
        }
    }

    // Отделяем от общей матрицы
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            EyeMatrix[i][j] = SupplemenMatrix[i][j + n];
        }
    }

    // Освобождаем память, выделенную под временные матрицы
    for (int i = 0; i < n; i++)
    {
        delete[] SupplemenMatrix[i];
    }
    delete[] SupplemenMatrix;

    matrix.matrix = EyeMatrix;
    return matrix;
}


int main()
{
    Matrix mat = ReadMatrixFromFile("matrix.txt");

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(mat);

    Matrix result = GaussJordan(mat);

    std::cout << "Inverse Matrix:" << std::endl;
    printMatrix(result);



    return 0;
}


