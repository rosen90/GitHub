#include <iostream>
using namespace std;

int main()
{

	int n, k;
	long factorial = 1, factK = 1;

	cout << "Enter values for n and k (N must be greater than K)" << endl;
	cout << "N= ";
	cin >> n;

	cout << "K= ";
	cin >> k;

	while (true)
	{
		if (n == 1)
		{
			break;
		}
		factorial *= n;
		n--;
	}

	while (true)
	{
		if (k == 1)
		{
			break;
		}
		factK *= k;
		k--;
	}

	if (factorial >= factK)
	{
		cout << "N! = " << factorial << endl;
		cout << "K! = " << factK << endl;
		cout << "N!/K! = " << factorial / factK;
	}
	else
	{
		cout << "Error: N must be greater than K .";
	}
	return 0;
}
