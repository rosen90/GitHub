#include <iostream>
using namespace std;

long Factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}

int main()
{

	int n;
	cout << "n = ";
	cin >> n;

	long factorial = Factorial(n);
	long factMultible2 = Factorial(2 * n);
	long factPlus1 = Factorial(n + 1);
	long catalanNum = factMultible2 / (factPlus1 * factorial);

	cout << "The catalan number is: " << catalanNum;

	return 0;
}
