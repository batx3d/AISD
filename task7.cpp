#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    void addNode(int value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            head->next = head; // Сделать список циклическим
        }
        else
        {
            Node* temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void josephus(int m)
    {
        Node* current = head;
        Node* prev = nullptr;
        int count = 1;

        while (current->next != current)
        {
            if (count == m)
            {
                if (prev)
                    prev->next = current->next;
                else
                    head = current->next;

                Node* temp = current;
                current = current->next;
                delete temp;
                count = 1;
            }
            else
            {
                prev = current;
                current = current->next;
                count++;
            }
        }

        cout << "value: " << current->data << endl;
    }
};

int main()
{
    int n = 20;

    for (int m = 2; m <= n; m++)
    {
        CircularLinkedList list;

        for (int i = 1; i <= n; i++)
        {
            list.addNode(i);
        }

        cout << "m = " << m << " ";
        list.josephus(m);
    }

    return 0;
}
