/*
* Выполнил: Владимир Матвеев
*
* Задача:
* Реализовать очередь:
* 1. С использованием массива.
* 2. С использованием односвязного списка.
*
* Задача решена с использованием односвязного списка (пункт 2), решение с использованием массива (пункт 1) опущенно.
*/
#include <iostream>

using namespace std;

struct Node
{
	int x;
	Node *Next;
};

Node *Head, *Tail;
int totalCount = 0;
void Enqueue(int x); // Добавление в очередь
int Dequeue();       // Изъятие из очереди
int Peek();          // Получение последнего элемента
void Show();         // Вывод очереди на экоан
void Clear();        // Очистка очереди

void Enqueue(int x)
{
	Node *tmp = new Node;
	tmp->x = x;
	tmp->Next = NULL;

	if (Head != NULL)
	{
		Tail->Next = tmp;
		Tail = tmp;
	}
	else
		Head = Tail = tmp;

	totalCount++;
}

void Clear()
{
	Node *tmp = Head;
	while (tmp != NULL)
	{
		tmp = Head->Next;
		delete Head;
		Head = tmp;
	}
	totalCount = 0;
}

void Show()
{
	Node *tmp = Head;
	while (tmp != NULL)
	{
		cout << tmp->x << " ";
		tmp = tmp->Next;
	}
	cout << endl;
}

int Dequeue()
{
	int result;
	if (Head != NULL)
	{
		Node *tmp = Head;
		Head = Head->Next;
		result = Head->x;
		delete tmp;
	}
	totalCount--;
	return result;
}

int Peek()
{
	return Head->x;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Enqueue(10);        //10
	Enqueue(20);        //10 20
	Enqueue(30);        //10 20 30
	Show();
	cout << Peek() << endl;
	Dequeue();          //20 30
	Show();
	Enqueue(40);        //20 30 40
	Dequeue();          //30 40
	Dequeue();          // 40
	Show();
	Clear();
	Show();
	system("PAUSE");
	return 0;
}