//3. Write a function that returns the last digit of an integer
//as an English word. Examples: 512  ”two”, 1024 
//”four”.

#include <iostream>
using namespace std;

void printLastDigit(int number)
{
	int digit = number % 10;

	switch(digit)
	{
	case 0: cout << "Zero"; break;
	case 1: cout << "One"; break;
	case 2: cout << "Two"; break;
	case 3: cout << "Three"; break;
	case 4: cout << "Four"; break;
	case 5: cout << "Five"; break;
	case 6: cout << "Six"; break;
	case 7: cout << "Seven"; break;
	case 8: cout << "Eight"; break;
	case 9: cout << "Nine"; break;
	}
}

int main()
{

	int number;

	cout << "Enter a number: ";
	cin >> number;

	cout << "The last digit is ";
	printLastDigit(number);

	return 0;
}
