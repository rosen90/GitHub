//c) Total the 100 elements of floating-point array c.

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{

	int array[100];
	int sum = 0;

	for(int i = 0; i < 100; i++)
	{
		array[i] = rand() % 100;
		sum += array[i];

	}

	cout << "Total sum is: " << sum;

	return 0;
}
