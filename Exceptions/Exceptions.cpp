// Exceptions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;

class NewException
{
	const string msg = "An easter egg, haha";
	friend ostream& operator<<(ostream& os, NewException a)
	{
		os << a.msg;
		return os;
	}
};

int main()
{
	//Обработка исключений

	setlocale(LC_ALL, "Russian");
	string input1, input2;

	while (true)
	{
		cout << "Делим число 1 на 2" << endl;
		cout << "Введите число 1: ";
		cin >> input1;
		while (cin.get() != '\n');

		cout << "Введите число 2: ";
		cin >> input2;
		while (cin.get() != '\n');

		double d1, d2, res;
		NewException a;

		try 
		{
			d1 = stod(input1);

			if (input2 == "Easteregg")
				throw a;
			else
				d2 = stod(input2);
			
		}
		catch (NewException)
		{
			cout << a << endl;
			continue;
		}
		catch (...)
		{
			cout << "Возникло исключение. Попробуйте снова." << endl;
			continue;
		}	

		try
		{
			if (d2 == 0)
				throw 1;
			else
			{
				res = d1 / d2; cout << res << endl;
			}
		}
		catch (int i)
		{
			cout << "Было выполнено деление на 0" << endl;
		}

	}


    return 0;
}

