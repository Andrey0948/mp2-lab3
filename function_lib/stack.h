#pragma once
#include <iostream>

using namespace std;

const int MaxStackSize = 100;

template <class T>
class Stack
{
	T* pStack;                      // указатель на стэк
	int size;                             // размер
	int element;                          // вершина стека
public:
	Stack(int s = 10);                    // конструктор
	Stack(const Stack& st);               // конструктор копирования
	~Stack();                             // деструктор
	void Push(T e);                 // добовление элемента в стек
	T Pop();                        // получение верхнего элемента с удалением из стека
	T Top();                        // доступ к верхнему элементу стека
	void Deltop();                        // удалить последний элемент

	bool IsEmpty()const;                  // проверка на пустоту стека
	bool IsFull()const;                   // проверка на заполненность стека
	 
	void Clear();                         // очистить
	int Length();
};

template <class T>
Stack<T>::Stack(int s)                       // конструктор
{
	size = s;
	pStack = new T[size]; 
	element = -1;
};

template <class T>                 
Stack<T>::Stack(const Stack<T>& st)   // конструктор копирования
{
	size = st.size;
	element = st.element;
	pStack = new ValType[size]; 
	for (int i = 0; i < element; i++)
	{
		pStack[i] = st.pStack[i];
	}
};

template <class T>
Stack<T>::~Stack()                      // деструктор
{
	delete[] pStack;
};

template <class T>
bool Stack <T>::IsEmpty() const        // стэк пуст
{
	return (element == -1);
};

template <class T>
bool Stack <T>::IsFull() const        // стэк полон
{
	return (element == size - 1);
};

template <class T>
void Stack<T>::Push(T el)              // добовление элемента в стек
{
	if (IsFull())
	throw "error: stack is full";
	element++;
	pStack[element] = el;               // помещаем элемент в стек
};

template <class T>
T Stack<T>::Pop()                 // получение верхнего элемента с удалением из стека
{
	if (IsEmpty())
	throw "error: stack is empty";
	return pStack[element--];
};

template <class T>
T Stack<T>::Top()                      // получение верхнего элемента без удаления 
{ 
	if (IsEmpty())
	throw "error: stack is empty";
	return pStack[element];
};

template <class T>
void Stack<T>::Deltop()                 // удалить последний элемент
{
	if (IsEmpty())
	throw "error: stack is empty";
	element--;
};

template <class T>
int Stack<T>::Length() //элементов в стэке в момент времени t.
{
	return element + 1;
};

template <class T>
void Stack<T>::Clear() // очистить
{
	element = -1;
};