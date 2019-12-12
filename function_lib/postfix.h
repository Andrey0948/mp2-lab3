#pragma once
#include "stack.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Postfix
{
	string infix; // ������, �������� ��������� � ��������� �����
	string postfix; // ������, �������� ��������� � ����������� �����
	double* value; // ��� �������� �������� ���������� ���������
	Stack<char> stackOperation; // ��� �������������� � �������� � �������� �� ������������
	Stack<string> stackArguments; // ��� �������� ����������
	Stack<double> stackValue; //��� �������� ��������������� ��������
	Stack<double> stackValuePostfix; //��� ������������ ����������

public:
	Postfix(string inf);
	string GetInfix(); // ������ � ��������� �����
	string GetPostfix(); // ������ � ���������� �����
	void ToPostfix(); // ��������� ���������
	double Calculate(); // ����������
	bool IsCorrect(); // �������� �� ������������ ���������
	bool IsNumber(char);
	bool IsOperation(char);
	const string oper = "+-*/";
	const string number = "123456789";
	void ChangeInfix(string inf);
	void ReadArguments(); //���� �������� ����������
};

bool Postfix::IsOperation(char x)
{
	if (oper.find(x) != string::npos)
		return 1;
	else
		return 0;
}
bool IsCompute(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Postfix::IsNumber(char x)
{
	if (number.find(x) != string::npos)
		return 1;
	else
		return 0;
};

int Priority(char x)
{
	//if (!IsOperation(x)) { throw "error: data is not correct"; }

	if (x == '(') { return 0; }
	else if (x == ')') { return 1; }
	else if (x == '+' || x == '-') { return 2; }
	else { return 3; }
}

double Total(double op1, double op2, char operation)
{
	if (operation == '+') { return op1 + op2; }
	else if (operation == '-') { return op1 - op2; }
	else if (operation == '*') { return op1 * op2; }
	else if (operation == '/') { return op1 / op2; }
	else { return 0; }
}

Postfix::Postfix(string inf)
{
	infix = inf;
	postfix = "";
	value = nullptr;
}

string Postfix::GetInfix()
{
	return infix;
}

string Postfix::GetPostfix()
{
	return postfix;
}

bool Postfix::IsCorrect() //�������� �� ������������ ���������
{
	stackOperation.Clear();
	int x = 0;

	if (IsCompute(infix[0]) || IsCompute(infix[infix.size() - 1])) // ��������� �� ���������� � �� ������������� ���������
	{
		return false;
	}

	for (int i = 1; i < infix.size() - 1; i++) // � ��������� ��� ���� �������� ������
	{
		if (IsCompute(infix[i]) && IsCompute(infix[i + 1]))
		{
			return false;
		}
	}

	for (int i = 1; i < infix.size(); i++) // �������� ������������ ������
	{
		if (infix[i] == '(')
		{
			x++;
		}
		if (infix[i] == ')')
		{
			x--;
		}
	}
	if (x != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void Postfix::ToPostfix() // ��������� ���������
{
	stackOperation.Clear();
	int a = 0;
	for (int i = 0; i < infix.size(); i++)
	{
		if (!IsOperation(infix[i]))
		{
			postfix += infix[i];
			if (i == infix.size() - 1 || IsOperation(infix[i + 1]))
				postfix += ' ';
		}
		else
		{
			if (infix[i] != ')')
			{
				if (Priority(infix[i]) == 0 || stackOperation.IsEmpty() || Priority(infix[i]) > Priority(stackOperation.Top()))
					stackOperation.Push(infix[i]);
				else
				{
					a = stackOperation.Length();
					for (int j = 0; j < a; j++)
					{
						if (Priority(stackOperation.Top()) >= Priority(infix[i]))
						{
							postfix += stackOperation.Pop();
							postfix += ' ';
						}
						else
							break;
					}
					stackOperation.Push(infix[i]);
				}
			}
			else
			{
				a = stackOperation.Length();
				for (int j = 0; j < a; j++)
				{
					if (stackOperation.Top() != '(')
					{
						postfix += stackOperation.Pop();
						postfix += ' ';
					}
					else
					{
						stackOperation.Deltop();
						break;
					}
				}
			}
		}
	}
	a = stackOperation.Length();
	for (int j = 0; j < a; j++)
	{
		postfix += stackOperation.Pop();
		if (j != a - 1)
			postfix += ' ';
	}
}

void Postfix::ChangeInfix(string inf)
{
	infix = inf;
	postfix.clear();
}

/*void Postfix::ReadArguments() //���� �������� ����������
{
	stackArguments.Clear();
	stackValue.Clear();
	string ss;
	for (int i = infix.size() - 1; i >= 0; i--)
		if (!IsOperation(infix[i]) && !IsNumber(infix[i]) && infix[i] != '.')
		{
			ss += infix[i];
			if (i != 0 && !IsOperation(infix[i - 1]) && !IsNumber(infix[i - 1]))
				continue;
			reverse(ss.begin(), ss.end());
			stackArguments.Push(ss);
			ss.clear();
		}
	int res = stackArguments.Length();
	value = new double[res];
	if (res)
		cout << "������� �������� ����������." << endl;
	for (int i = 0; i < res; i++)
	{
		cout << stackArguments.Pop() << "=";
		cin >> value[i];
	}
	for (int i = res - 1; i >= 0; i--)
		stackValue.Push(value[i]);
}*/

double Postfix::Calculate() // ����������
{
	stackValuePostfix.Clear();
	double tmp = 0;
	string ss;
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] != ' ')
		{
			if (!IsOperation(postfix[i]) && !IsNumber(postfix[i]) && postfix[i] != '.')
			{
				if (i != postfix.size() - 1 && postfix[i + 1] != ' ')
					continue;
				stackValuePostfix.Push(stackValue.Pop());
			}
			else if (IsNumber(postfix[i]) || postfix[i] == '.')
			{
				ss += postfix[i];
				if (i != postfix.size() - 1 && IsNumber(postfix[i + 1]))
					continue;
				if (postfix[i + 1] == '.')
					continue;
				tmp = stod(ss);
				stackValuePostfix.Push(tmp);
				ss.clear();
			}
			else
			{
				tmp = Total(stackValuePostfix.Pop(), stackValuePostfix.Pop(), postfix[i]);
				stackValuePostfix.Push(tmp);
			}
		}
		else continue;
	}
	return stackValuePostfix.Pop();
}