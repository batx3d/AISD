#include <iostream>
#include <limits>
#include <Windows.h>

using namespace std;

const int n = 4; // Количество вершин в графе
const int postalOffice = 0; // Номер почтамта

// Функция для поиска кратчайшего пути от начальной вершины до всех остальных вершин
void dijkstra(int graph[n][n], int start, int distance[])
{
    bool visited[n] = { false };

    distance[start] = 0;

    for (int i = 0; i < n; ++i)
    {
        int u = -1;
        for (int j = 0; j < n; ++j)
        {
            if (!visited[j] && (u == -1 || distance[j] < distance[u]))
            {
                u = j;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] != -1 && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    // Расстояния между П и ОС
    int graph[n][n] = {
        {-1, 5, 3, 4},
        {5, -1, 4, 7},
        {3, 4, -1, 7},
        {4, 7, 7, -1}
    };

    int distances[n];

    // Инициализация массива расстояний
    for (int i = 0; i < n; ++i)
    {
        distances[i] = INT_MAX;
    }

    // Вычисление кратчайших расстояний от П до ОС и обратно
    dijkstra(graph, postalOffice, distances);

    // Вывод результатов
    cout << "Кратчайшие расстояния от почтамта до отделений связи и обратно:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "П-" << i + 1 << ": " << distances[i] << " км" << endl;
    }

    return 0;
}
