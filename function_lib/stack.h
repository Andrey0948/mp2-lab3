#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack
{
    T *Stack;                   // указатель на стек
	int size;                   // размер стека
public:
	Stack(int = 10);            // по умолчанию размер стека равен 10 элементам
	~Stack();                   // деструктор
	void Push(const T &m);      // поместить элемент в стек
	void Pop();                 // достать из стека элемент
	bool IsEmpty()const;
	bool IsFull()const;
};

template <class T> // конструктор
Stack<T>::Stack(int s)
{
	size = s;
	element = 0; // текущий элемент равен нулем;
	Stack = new T[size]; // выделить память под стек
}

template <class T> // конструктор копирования
Stack<T>::Stack(const StackT>& st)
{
	size = st.size;
	element = st.element;
	Stack = new T[size]; // выделить память под новый стек
	for (int i = 0; i < element; i++)
	{
	  Stack[i] = st.Stack[i];
	}
}

template <class T> // деструктор
Stack <T> :: ~Stack()
{
	delete[] Stack; // удаляем стек
}

template <class T> // функция добавления элемента в стек
void Stack<T>::Push(const T& m)
{
	// проверяем размер стека
	if (element < size) // номер текущего элемента должен быть меньше размера стека
	{
		throw "Stack is full";
	}
    Stack[element++] = m; // помещаем элемент в стек

}

template <class ValType>
void Stack<ValType>::Pop() // функция удаления элемента из стека
{
	// проверяем размер стека
	if (element > 0) // номер текущего элемента должен быть больше 0
	{
		throw "Stack is empty";
	}
	int a = pStack[element];
	element--;
}

template <class ValType>
bool Stack <ValType> ::IsEmpty() const
{
	return (element == -1)
}

template <class ValType>
bool Stack <ValType> ::IsFull() const
{
	return (element >= size);
}