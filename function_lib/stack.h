#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack
{
    T *pStack;                   // ��������� �� ����
	int size;                   // ������ �����
	int element;
public:
	Stack(int = 10);            // �� ��������� ������ ����� ����� 10 ���������
	Stack(const Stack &st);
	~Stack();                   // ����������
	void Push(const T &m);      // ��������� ������� � ����
	void Pop();                 // ������� �� ����� �������
	bool IsEmpty() const;
	bool IsFull() const;
};

template <class T> 
Stack<T>::Stack(int s)
{
	size = s;
	element = 0;
	pStack = new T[size];
}

template <class T>
Stack<T>::Stack(const StackT>& st)
{
	size = st.size;
	element = st.element;
	pStack = new T[size];
	for (int i = 0; i < element; i++)
	{
	  pStack[i] = st.pStack[i];
	}
}

template <class T>
Stack <T> :: ~Stack()
{
	delete[] pStack;
}

template <class T>                // ��������� ������� � ����
void Stack<T>::Push(const T& m)
{
	if (element < size)
	{
		throw "Stack is full";
	}
    pStack[element++] = m;

}

template <class ValType>
void Stack<ValType>::Pop()        // ������� ������� �� �����
{
	if (element > 0)
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