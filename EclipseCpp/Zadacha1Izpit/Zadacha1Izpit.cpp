//Напишете програма, която отпечатва всички четерицифрени числа от вида ABCD такива че:
//(a + 3d)^2 = 4b + c^3

#include <iostream>
using namespace std;

int main()
{
	int number, a, b, c, d;


	cout << "The numbers are: " << endl;

	for (int i = 1000; i <= 9999; i++)
	{
			number = i;
			a = number / 1000;
			b = (number % 1000) / 100;
			number = number % 100;
			c = number / 10;
			d = number % 10;

			if((a + 3*d) * (a + 3*d) == 4*b + (c*c*c))
			{
				cout << i << endl;
			}
	}



	return 0;
}
