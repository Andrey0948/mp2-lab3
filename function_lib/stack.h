#pragma once
#include <iostream>

using namespace std;

const int MaxStackSize = 100;

template <class T>
class Stack
{
	T* pStack;                      // ��������� �� ����
	int size;                             // ������
	int element;                          // ������� �����
public:
	Stack(int s = 10);                    // �����������
	Stack(const Stack& st);               // ����������� �����������
	~Stack();                             // ����������
	void Push(T e);                 // ���������� �������� � ����
	T Pop();                        // ��������� �������� �������� � ��������� �� �����
	T Top();                        // ������ � �������� �������� �����
	void Deltop();                        // ������� ��������� �������

	bool IsEmpty()const;                  // �������� �� ������� �����
	bool IsFull()const;                   // �������� �� ������������� �����
	 
	void Clear();                         // ��������
	int Length();
};

template <class T>
Stack<T>::Stack(int s)                       // �����������
{
	size = s;
	pStack = new T[size]; 
	element = -1;
};

template <class T>                 
Stack<T>::Stack(const Stack<T>& st)   // ����������� �����������
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
Stack<T>::~Stack()                      // ����������
{
	delete[] pStack;
};

template <class T>
bool Stack <T>::IsEmpty() const        // ���� ����
{
	return (element == -1);
};

template <class T>
bool Stack <T>::IsFull() const        // ���� �����
{
	return (element == size - 1);
};

template <class T>
void Stack<T>::Push(T el)              // ���������� �������� � ����
{
	if (IsFull())
	throw "error: stack is full";
	element++;
	pStack[element] = el;               // �������� ������� � ����
};

template <class T>
T Stack<T>::Pop()                 // ��������� �������� �������� � ��������� �� �����
{
	if (IsEmpty())
	throw "error: stack is empty";
	return pStack[element--];
};

template <class T>
T Stack<T>::Top()                      // ��������� �������� �������� ��� �������� 
{ 
	if (IsEmpty())
	throw "error: stack is empty";
	return pStack[element];
};

template <class T>
void Stack<T>::Deltop()                 // ������� ��������� �������
{
	if (IsEmpty())
	throw "error: stack is empty";
	element--;
};

template <class T>
int Stack<T>::Length() //��������� � ����� � ������ ������� t.
{
	return element + 1;
};

template <class T>
void Stack<T>::Clear() // ��������
{
	element = -1;
};