//5. Write program that for a given digit (0-9) entered
//as input prints the name of that digit (in Bulgarian).
//Use a switch statement.

#include <iostream>
#include <windows.h>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);

	int number;

	cout << "Enter a digit in range 0-9: ";
	cin >> number;

	if(number < 0 || number > 9)
	{
		cout << "The number is not in range!";
	}
	else
	{
		switch(number)
		{
		case 0: cout << "нула"; break;
		case 1: cout << "едно"; break;
		case 2: cout << "две"; break;
		case 3: cout << "три"; break;
		case 4: cout << "четири"; break;
		case 5: cout << "пет"; break;
		case 6: cout << "шест"; break;
		case 7: cout << "седем"; break;
		case 8: cout << "осем"; break;
		case 9: cout << "девет"; break;
		}
	}

	return 0;
}
