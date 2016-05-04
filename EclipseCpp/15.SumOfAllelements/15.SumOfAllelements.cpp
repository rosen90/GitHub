//1. Намерете сумата на всички елементи в масив от 100 елемента.
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
		sum += array[i];
	}

	cout << "The total sum of all array elements is " << sum;


	return 0;
}
