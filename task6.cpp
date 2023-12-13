#include <iostream>
#include <stack>
#include <sstream>
#include <Windows.h>
#include <algorithm>
using namespace std;

// Структура для узла стека
struct Node {
    string word;
    Node* next;

    Node(const string& w) : word(w), next(nullptr) {}
};

// Класс для представления стека
class Stack {
private:
    Node* top; // Указатель на вершину стека

public:
    Stack() : top(nullptr) {}

    // Функция для добавления слова в стек
    void push(const string& word)
    {
        Node* newNode = new Node(word);
        newNode->next = top;
        top = newNode;
    }

    // Функция для удаления слова из стека
    void pop()
    {
        if (isEmpty())
        {
            cerr << "Стек пуст." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Функция для проверки, пуст ли стек
    bool isEmpty() const
    {
        return top == nullptr;
    }

    // Функция для вывода слов в прямом порядке
    void printForward() const
    {
        Node* current = top;
        while (current != nullptr)
        {
            cout << current->word << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создаем стек
    Stack wordStack;

    // Предложение для добавления в стек
    string sentence = "Разработать алгоритм и программу умножения двух целочисленных матриц.";
    reverse(sentence.begin(), sentence.end());
    // Используем stringstream для разделения предложения на слова
    istringstream iss(sentence);
    string word;


    // Заносим слова в стек в обратном порядке
    while (iss >> word)
    {
        reverse(word.begin(), word.end());
        wordStack.push(word);
    }

    // Выводим предложение на экран пословно в прямом порядке
    cout << "Предложение в прямом порядке: ";
    wordStack.printForward();



    return 0;
}
