//2. Намерете сумата на елементите с четна стойнност в масив със 100 елемента.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));

	int array[100];
	int sum = 0;

	for(int i = 0; i < 100; i++)
	{
		array[i] = 1 + rand() % 100;

		if(array[i] % 2 == 0)
		{
			sum += array[i];
		}
	}

	cout << "The total sum of even array elements is " << sum;

	return 0;
}
