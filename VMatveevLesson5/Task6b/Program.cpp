/*
* Выполнил: Владимир Матвеев
*
* Задача:
* Реализовать двустороннюю очередь (Дек).
*
* Решение с использованием двухсвязного списка.
*/
#include <iostream>

using namespace std;

struct Node
{
	int x;
	Node *Next;
	Node *Prev;
};

Node *Head, *Tail;
int totalCount = 0;
void Enqueue(int x); // Добавление в начало (очередь)
void Push(int x);    // Добавление в конец (очередь)
int PeekHead();      // Получение значения первого элемента
int PeekTail();      // Получение значения последнего элемента
int Dequeue();       // Получение значения первого элемента и удаление элемента
int Pop();           // Получение значения последнего элемента и удаление элемента
void Show();         // Вывод на экоан
void Clear();        // Очистка

void Enqueue(int x)
{
	Node *tmp = new Node;
	tmp->x = x;
	tmp->Next = NULL;
	tmp->Prev = NULL;

	if (Head != NULL)
	{
		Tail->Next = tmp;
		tmp->Prev = Tail;
		Tail = tmp;
	}
	else
		Head = Tail = tmp;

	totalCount++;
}

int Dequeue()
{
	int result;
	if (Head != NULL)
	{
		Node *tmp = Head;
		Head = Head->Next;
		Head->Prev = NULL;
		result = Head->x;
		delete tmp;
	}
	totalCount--;
	return result;
}

int PeekHead()
{
	int result;
	if (Head != NULL)
	{
		result = Head->x;
	}
	return result;
}

void Push(int x)
{
	Node *tmp = new Node;
	tmp->x = x;
	tmp->Next = NULL;
	tmp->Prev = NULL;

	if (Head != NULL)
	{
		tmp->Next = Head;
		Head->Prev = tmp;
		Head = tmp;
	}
	else
		Head = Tail = tmp;

	totalCount++;
}

int Pop()
{
	int result;
	if (Head != NULL)
	{
		result = Tail->x;
		Node *tmp = Tail;
		Tail = Tail->Prev;
		Tail->Next = NULL;
		delete tmp;
	}
	totalCount--;
	return result;
}

int PeekTail()
{
	int result;
	if (Tail != NULL)
	{
		result = Tail->x;
	}
	return result;
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

void Clear()
{
	Node *tmp = Head;
	while (tmp != NULL)
	{
		tmp = Head->Next;
		delete Head;
		Head = tmp;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	Enqueue(10);        //10
	Enqueue(20);        //10 20
	Enqueue(30);        //10 20 30
	Push(5);            //5 10 20 30
	Push(2);            //2 5 10 20 30
	Pop();              //2 5 10 20
	Dequeue();          //5 10 20
	Push(2);            //2 5 10 20
	Enqueue(40);        //2 5 10 20 40
	Show();
	cout << PeekTail() << " " << PeekHead() << endl;
	Clear();
	system("PAUSE");
	return 0;
}