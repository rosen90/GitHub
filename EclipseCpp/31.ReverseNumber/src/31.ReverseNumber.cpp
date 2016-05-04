#include <iostream>
using namespace std;

int main()
{
	int number, temp;
	cout << "Enter a number: ";
	cin >> number;

	while (number != 0)
	        {

	            temp = number % 10;

	            number = number / 10;

	            cout << temp;
	        }

	return 0;
}
