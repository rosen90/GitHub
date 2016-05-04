//4. Проверете дали 2 масива от по 100 елемента са равни.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));

	int array[100];
	int secondArray[100];

	for(int i = 0; i < 100; i++)
	{
		array[i] = 1 + rand() % 100;

		secondArray[i] = 1 + rand() % 100;

		if(array[i] != secondArray[i])
		{
			cout << "The array are not equal";
			break;
		}
		else
		{
			cout << "The array are equals";
		}
	}




	return 0;
}
