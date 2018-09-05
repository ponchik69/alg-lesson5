/*
* ��������: �������� �������
*
* ������:
* ����������� ������������ ������� (���).
*
* ������� � �������������� ������������ ������.
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
void Enqueue(int x); // ���������� � ������ (�������)
void Push(int x);    // ���������� � ����� (�������)
int PeekHead();      // ��������� �������� ������� ��������
int PeekTail();      // ��������� �������� ���������� ��������
int Dequeue();       // ��������� �������� ������� �������� � �������� ��������
int Pop();           // ��������� �������� ���������� �������� � �������� ��������
void Show();         // ����� �� �����
void Clear();        // �������

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

	if (Head != NULL)
	{
		tmp->Next = Head;
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
		Tail = Head;
		for(int i=0; i < totalCount-2;i++)
		{
			Tail = Tail->Next;
		}
		Tail->Next = NULL;
		delete tmp;
		totalCount--;
	}
	return result;
}

int PeekTail()
{
	int result;
	if (Head != NULL)
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
	totalCount = 0;
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
	Show();
	cout << PeekTail()  << " " << PeekHead() << endl;
	Clear();

	system("PAUSE");
	return 0;
}