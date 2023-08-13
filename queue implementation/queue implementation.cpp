#include <iostream>
#include <windows.h>

using namespace std;
struct Node {
    int data;
    Node* next;
};

void push(int elem, Node*& Head, Node*& Tail) {
    Node* newElem = new Node;
    newElem->data = elem;
    newElem->next = NULL;

    if (Tail == NULL) {
        Tail = newElem;
        Head = newElem;
    }
    Tail->next = newElem;
    Tail = newElem;
}

int pop(Node*& Head, Node*& Tail) {
    if (Head == NULL) return 0;
    int tmp = Head->data;
    Node* newElem = Head;
    Head = Head->next;
    delete newElem;
    if (Head == NULL) Tail = NULL;
    return tmp;
}

int peek(Node* Head) {
    if (Head == NULL) return 0;
    return Head->data;
}

void print(Node* Head) {
    if (Head == NULL) {
        cout << "Очередь пуста\n";
        return;
    }
    cout << "Очередь (с начала): ";
    while (Head) {
        cout << Head->data << " ";
        Head = Head->next;
    }
    cout << endl;
}

void clear(Node*& Head, Node*& Tail) {
    while (Head) {
        Node* newElem = Head;
        Head = Head->next;
        delete newElem;
    }
    Tail = NULL;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* Tail = NULL, * Head = NULL;
    int choice;
    int number;
    while (true) {
        cin >> choice;
        switch (choice) {
        case 1:
            cin >> number;
            push(number, Head, Tail);
            break;
        case 2:
            cout << "Извлечено: " << pop(Head, Tail) << endl;
            break;
        case 3:
            cout << "Первый: " << peek(Head) << endl;
            break;
        case 4:
            print(Head);
            break;
        case 5:
            clear(Head, Tail);
            break;
        default:
            clear(Head, Tail);
            return 0;
        }
    }
}