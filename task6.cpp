#include <iostream>
#include <stack>
#include <sstream>
#include <Windows.h>
#include <algorithm>
using namespace std;

// ��������� ��� ���� �����
struct Node {
    string word;
    Node* next;

    Node(const string& w) : word(w), next(nullptr) {}
};

// ����� ��� ������������� �����
class Stack {
private:
    Node* top; // ��������� �� ������� �����

public:
    Stack() : top(nullptr) {}

    // ������� ��� ���������� ����� � ����
    void push(const string& word)
    {
        Node* newNode = new Node(word);
        newNode->next = top;
        top = newNode;
    }

    // ������� ��� �������� ����� �� �����
    void pop()
    {
        if (isEmpty())
        {
            cerr << "���� ����." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // ������� ��� ��������, ���� �� ����
    bool isEmpty() const
    {
        return top == nullptr;
    }

    // ������� ��� ������ ���� � ������ �������
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

    // ������� ����
    Stack wordStack;

    // ����������� ��� ���������� � ����
    string sentence = "����������� �������� � ��������� ��������� ���� ������������� ������.";
    reverse(sentence.begin(), sentence.end());
    // ���������� stringstream ��� ���������� ����������� �� �����
    istringstream iss(sentence);
    string word;


    // ������� ����� � ���� � �������� �������
    while (iss >> word)
    {
        reverse(word.begin(), word.end());
        wordStack.push(word);
    }

    // ������� ����������� �� ����� �������� � ������ �������
    cout << "����������� � ������ �������: ";
    wordStack.printForward();



    return 0;
}
