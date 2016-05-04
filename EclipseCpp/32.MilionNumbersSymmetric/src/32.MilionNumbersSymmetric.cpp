#include <iostream>
using namespace std;

int main()
{
	int checkSum, rem, sum = 0, temp, temp2, temp3, sum2 = 0;
	cout << "Enter a sum: ";
	cin >> checkSum;

	for (int i = 1; i < 1000000; i++)
	{

		temp2 = i;

		if (temp2 == sum)
		{
			while (temp2 != 0)
			{

				temp3 = temp2 % 10;

				temp2 = temp2 / 10;

				sum2 += temp3;

			}
		}

		if (sum2 == checkSum)
		{
			cout << i << ", ";
		}

		sum = 0;
		sum2 = 0;

	}

	return 0;
}
