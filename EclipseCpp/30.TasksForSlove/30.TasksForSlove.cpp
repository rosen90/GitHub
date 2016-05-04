//4. Write a program that can solve these tasks:
//– Reverses the digits of a number
//– Calculates the average of a sequence
//– Solves a linear equation a * x + b = 0
//Create appropriate functions.
//Provide a simple text-based menu for the user to
//choose which task to solve.
//Validate the input data:
//– The decimal number should be non-negative
//– The sequence should not be empty
//– a should not be equal to 0

#include <iostream>
#include <cstdlib>
using namespace std;

int reverseNumber(int number)
{
	int  sum = 0;

	while (number != 0)
	{
		int temp = number  % 10;
		number = number / 10;
	    sum = sum * 10 + temp;
	}

	return sum;
}

int average(int size)
{
	int sequance[size];
	int sum = 0;

	for(int i = 0; i < size; i++)
	{
		cout << "Enter " << i+1 << " number: ";
		cin >> sequance[i];
		sum += sequance[i];
	}

	int average = sum / size;

	return average;
}

int equation(int a, int b)
{
	int x;

//	a * x + b = 0
	x = -b / a;
	return x;
}

void menu()
{
	int choice;
	cout << "Main menu" << endl;
	cout << "What task do you want to solve?" << endl;

	cout << "1) Reverse given number." << endl;
	cout << "2) Calculates the average of a sequence of numbers" << endl;
	cout << "3) Solves a linear equation a * x + b = 0." << endl;

	cin >> choice;

	int number, size, a, b;
	switch(choice)
	{
	case 1:
		system("CLS");
		cout << "Enter number for reverse: ";
		cin >> number;
		cout << "The reverse number is " << reverseNumber(number);
		break;
	case 2:
		system("CLS");
		cout << "How many number you want to calculate: ";
		cin >> size;
		cout << "The average sum is " << average(size);
		break;
	case 3:
		system("CLS");
		cout << "a= ";
		cin >> a;
		cout << "b= ";
		cin >> b;
		cout << "x = " << equation(a, b); break;
	}

}

int main()
{
	menu();
	return 0;
}
