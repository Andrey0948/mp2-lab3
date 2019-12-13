#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
	int a = 0;
	setlocale(LC_CTYPE, "Russian");
	string expression;
m:cout << "Введите арифметическое выражение" << endl;
	
	cin >> expression;
	Postfix postfix(expression);
if (!postfix.IsCorrect())
{
	cout << "Выражение не корректно, повторите." << endl;
	goto m;
}

  postfix.ToPostfix();
  cout << "Результат вычисления: " << postfix.Calculate() << endl;
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
  return 0;
}