//8. Намерете най-големия елемент в двумерен масив.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	srand(time(0));

	int array[5][5];
	int maxElement;

	for(int row = 0; row < 5; row++)
	{
		for(int col = 0; col < 5; col++)
		{
			array[row][col] = 1 + rand() % 100;
		}
	}

	maxElement = array[0][0];

	for(int row = 0; row < 5; row++)
	{
		for(int col = 0; col < 5; col++)
		{
			if(array[row][col] > maxElement)
			{
				maxElement = array[row][col];
			}
		}
	}

	cout << "The biggest element of the array is " << maxElement;


	return 0;
}
