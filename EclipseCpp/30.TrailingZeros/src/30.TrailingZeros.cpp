#include <iostream>
using namespace std;

static long long Factorial(int n)
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
	cout << "Enter N: ";
	cin >> n;

	long long fact = Factorial(n);
	int trailing = n / 5;
	cout << "Trailing zeros in " << n << "! are: " << trailing << endl;
	cout << "The value of " << n << "! is: " << fact;


	return 0;
}
