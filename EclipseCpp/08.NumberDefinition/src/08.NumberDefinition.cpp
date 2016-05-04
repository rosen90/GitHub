#include <iostream>
using namespace std;

int main() {

	int number;
	cout << "Enter a nubmer: ";
	cin >> number;

	if(number < 0 && number % 2 == 0)
	{
		cout << "The number is negative and even";
	}
	else if(number == 0)
	{
		cout << "The number zero";
	}
	else if(number > 0 && number % 2 != 0)
	{
		cout << "The number is positive and odd";
	}

	return 0;
}
