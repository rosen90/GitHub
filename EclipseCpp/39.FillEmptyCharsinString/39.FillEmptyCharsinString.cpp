//5. Write a program that lets the user input a string of
//maximum 20 characters. If the length of the string is
//less, the rest of the characters should be filled with '*'.
//Print the string into the console.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int a;
	cout << "Enter string with maximum of 20 characters";
	getline(cin, str);

	if(str.length() <= 20)
	{
		cout << str;
		a = 20 - str.length();

		for(int i = 0; i < a; i++)
			{
				cout << "*";
			}
	}
	else
	{
		cout << "The string must be less of 20 characters";
	}

	return 0;
}
