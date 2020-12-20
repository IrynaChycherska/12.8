#include <iostream>
#include <cstring>
using namespace std;
typedef int Info;
struct Elem
{
	Elem* next,
		* prev;
	Info info;
};
void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);

int main()
{

	Elem* first = NULL,
		* last = NULL;
	for (int i = 1; i <= 10; i++)
		enqueue(first, last, i);
	while (first != NULL)
		cout << dequeue(first, last) << " ";
	cout << endl;
	return 0;

}
void enqueue(Elem*& first, Elem*& last, Info value)
{

	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->next = NULL;
	if (last != NULL)
	{
		Elem* T = last;
		while (T->next != last)
			T = T->next;
		T->next = tmp;
		tmp->prev = last;
	}
	else
	{
		last = tmp;
	}
	if (first == NULL)
		first = tmp;
	tmp->next = last;
}
void insert(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	if (last != NULL)
	{
		Elem* T = last;
		while (T->next != last)
			T = T->next; // 3
		T->next = tmp;
		tmp->prev = last;
	}
	else
	{
		last = tmp; // 5
	}
	if (first == NULL)
		first = tmp;
	tmp->next = last;
}
Info remove(Elem*& first, Elem*& last)
{
	Elem* T = last;
	while (T->next != last)
		T = T->next; // 1
	Info value = last->info; // 2
	if (T != last, T != first)
	{
		Elem* tmp = last->next; // 3
		delete last; // 4
		last = tmp; // 5
		T->next = last; // 6
	}
	else
	{
		delete last;
		first = NULL;// 4
		last = NULL; // 7
	}
	return value;
}
Info dequeue(Elem*& first, Elem*& last)
{
	Elem* T = first;
	while (T->next != last)
		T = T->next;
	Info value = first->info;
	if (T != first, T != last)
	{
		Elem* tmp = first->next;
		delete T;
		first = tmp;
	}
	else
		delete T;
	first = NULL;
	last = NULL;
	return value;
}
