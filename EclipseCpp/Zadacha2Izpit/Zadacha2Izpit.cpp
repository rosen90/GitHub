//Напишете програма, която намира всички прости числа в интервал от N до М
//(1 < N < M) такива, при които сумата от цифрите им е по голяма от K

#include <iostream>
using namespace std;

int main() {

	int N, M, K, prime, temp, sum = 0, check;

	cout << "N= ";
	cin >> N;

	cout << "M= ";
	cin >> M;

	cout << "K= ";
	cin >> K;

	cout << "The numbers are: " << endl;

	for (int i = N + 1; i < M; i++)
	{
		prime = 1;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				prime = 0;
				break;
			}
		}

		if (prime == 1)
		{
			check = i;
			while (check != 0)
			{
				temp = check % 10;
				check = check / 10;
				sum += temp;
			}

		}

		if (sum > K)
		{
			cout << i << endl;
		}

		sum = 0;
	}

	return 0;
}
