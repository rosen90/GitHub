#include <iostream>
using namespace std;

int main()
{

	int number = 58385, rem, sum = 0;
	int temp = number;

	while(number != 0)
	{
		rem = number % 10;
		number = number / 10;
		sum = sum * 10 + rem;
	}

	if(temp == sum)
	{
		cout << "This number 58385 is symmetric";
	}
	else
	{
		cout << "This number 58385 is not symmetric";
	}

	return 0;
}
