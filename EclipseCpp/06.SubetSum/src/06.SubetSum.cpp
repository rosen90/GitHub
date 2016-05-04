#include <iostream>
using namespace std;

int main() {

	int number, i;
	int sum = 0;

	for(i = 1; i <= 3; i ++)
	{
		cout << "Enter " << i << "number:";
		cin >> number;

		sum += number;
	}

	if(sum == 0)
	{
		cout << "Subset sum is 0 !!";
	}
	else
	{
		cout << "Subset sum is not 0";
	}

	return 0;
}
