#include <iostream>
using namespace std;

int main()
{
	cout << "n= ";
	int n = 0; cin >> n;
	cout << "n! = ";

	long factorial = 1;

	while(true)
	{
		cout << n;

		if(n == 1)
		{
			break;
		}

		cout << " * ";
		factorial *=n;
		n--;
	}

	cout << " = " << factorial << endl;

	return 0;
}
