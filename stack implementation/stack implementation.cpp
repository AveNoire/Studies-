#include <iostream>
#include <windows.h>
using namespace std;

struct Stack {
	int data;
	Stack* next;	
};

void push(int elem, Stack* &top) {
	Stack* newElem = new Stack;
	newElem->data = elem;
	newElem->next = top;
	top = newElem;
}

int pop(Stack*& top) {
	if (top == NULL) return 0;
	int tmp = top->data;
	Stack* elem = top;
	top = top->next;
	delete elem;
	return tmp;
}

int peek(Stack* top) {
	if (top == NULL) return 0;
	return top->data;
}

void print(Stack* top) {
	if (top == NULL) {
		cout << "Стек пуст\n";
		return;
	}
	cout << "Содержимое стека от вершины: ";
	while (top) {
		cout << top->data << " ";
		top = top->next; 
	}
	cout << endl;
}
void clear(Stack*& top) {
	while (top) {
		Stack* knot = top;
		top = top->next; 
		delete knot;
	}
}

int menu() {
	int choice = 0;
	do {
		cout << "\n1 - Добавление в стек\n";
		cout << "2 - Удаление из стека\n";
		cout << "3 - Чтение вершины стека\n";
		cout << "4 - Печать стека\n";
		cout << "5 - Очистка стека\n";
		cout << "6 - Завершение работы\n";
		cout << "Ваш выбор: ";
		cin >> choice;
		if (choice < 1 || choice>6) {
			cout << "Неверный выбор! Повторите ввод!\n";
		}
	} while (choice < 1 || choice>6);
	return choice;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Stack* top = NULL;
	int data;
	while (true) {
		int k = menu();
		switch (k) {
		case 1:
			cout << "Введите число: ";
			cin >> data;
			push(data, top);
			break;
		case 2:
			cout << "Извлечено из стека: " << pop(top) << endl;
			break;
		case 3:
			cout << "Прочитано из вершины: " << peek(top) << endl;
			break;
		case 4:
			print(top);
			break;
		case 5:
			clear(top);
			break;
		case 6:
			cout << "Завершение работы...";
			system("pause");
			clear(top);
			return 0;
		}
	}
}
