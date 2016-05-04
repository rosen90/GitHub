#include <iostream>
using namespace std;

int main()
{
//	int n, m, prime = 1;
//
//	cout << "Enter n: ";
//	cin >> n;

//	cout << "Enter m: ";
//	cin >> m;
//
//
//	for(int i = n + 1; i < m; i++)
//	{
//		prime = 1;
//
//		for(int j = 2; j < i; j++)
//		{
//			if(i % j == 0)
//			{
//				prime = 0;
//				break;
//			}
//		}
//
//		if(prime == 1)
//		{
//			cout << i << " ";
//		}
//	}

	int n, sum = 0, check, temp;
	check = n;

	cin >> n;

	while (n != 0)
	{
		temp = n%10;
		n = n/10;
		sum = sum * 10 + temp;
	}

	cout << sum;

	return 0;
}
