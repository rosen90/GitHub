#include <iostream>

using namespace std;

int main()
{
	int n, k, nMinusK;
	long factorial = 1, factK = 1, factNmK = 1;

	cout << "Enter values for n and k (N must be greater than K)" << endl;
	cout << "N= ";
	cin >> n;

	cout << "K= ";
	cin >> k;

	nMinusK = n - k;

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

	while(true)
	{
		if (nMinusK == 1)
		{
			break;
		}
		factNmK *= nMinusK;
		nMinusK--;
	}

	long double result = (factorial * factK)/factNmK;

	if (factorial >= factK)
		{
			cout << "N! = " << factorial << endl;
			cout << "K! = " << factK << endl;
			cout << "(N-K)! = " << factNmK;
			cout << "N!*K!/(N-K)! = " << result;

		}
		else
		{
			cout << "Error: N must be greater than K .";
		}

	return 0;
}
