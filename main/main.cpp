#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
	int a = 0;
	setlocale(LC_CTYPE, "Russian");
	string expression;
m:cout << "������� �������������� ���������" << endl;
	
	cin >> expression;
	Postfix postfix(expression);
if (!postfix.IsCorrect())
{
	cout << "��������� �� ���������, ���������." << endl;
	goto m;
}

  postfix.ToPostfix();
  cout << "��������� ����������: " << postfix.Calculate() << endl;
  cout << "����������� �����: " << postfix.GetPostfix() << endl;
  return 0;
}