//8. We are given 3 integer numbers. Write a program
//that checks if the sum of some subset of them is
//equal to 0.
//Examples:
//Given -2, -1, 1, the sum of 1 and -1 is 0.
//Given 3, 1, -7, no subset exists with sum 0.

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
