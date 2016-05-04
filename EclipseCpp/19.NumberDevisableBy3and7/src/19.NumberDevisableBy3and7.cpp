#include <iostream>
using namespace std;

int main()
{

	int number;

	cout << "Enter a number: ";
	cin >> number;

	for(int i = 1; i <= number; i++)
	{
		if(!(i % 3 == 0 || i % 7 == 0))
		{
			cout << i << ", ";
		}
	}

	return 0;
}
