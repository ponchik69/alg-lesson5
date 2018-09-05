/*
* Выполнил: Владимир Матвеев
*
* Задача:
* Создать функцию, копирующую односвязный список.

* В качестве односвязного списка всята очередь из задачи 5, посему методы заполнения и вывода на экран являются идентичными.
*/

#include <iostream>

using namespace std;

struct Node
{
	int x;
	Node *Next;
};

Node *Head, *Tail;
void Enqueue(int x);
void Show(Node *Start);

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
}

void Show(Node *Start)
{
	Node *tmp = Start;
	while (tmp != NULL)
	{
		cout << tmp->x << " ";
		tmp = tmp->Next;
	}
	cout << endl;
}

void Copy(Node *Start)
{
	Node *tmp = Start;

	while (tmp != NULL)
	{
		Enqueue(tmp->x);
		tmp = tmp->Next;
	}

}

int main()
{
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < 20; i++)
		Enqueue(i);

	Node *HeadOne = Head;
	Node *TailOne = Tail;
	Head = NULL;
	Tail = NULL;
	Show(HeadOne);
	Copy(HeadOne);
	Node *HeadTwo = Head;
	Node *TailTwo = Tail;
	Show(HeadTwo);

	system("PAUSE");
	return 0;
}