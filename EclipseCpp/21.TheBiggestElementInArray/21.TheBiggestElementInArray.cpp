//7. Намерете най-големия елемент в едномерен масив.
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

	int array[20];
	int maxElement;

	for(int i = 0; i < 20; i++)
	{
		array[i] = 1 + rand() % 100;
	}

	maxElement = array[0];

	for(int i = 0; i < 20; i++)
	{
		if(array[i] > maxElement)
		{
			maxElement = array[i];
		}
	}

	cout << "The biggest element of the array is " << maxElement;


	return 0;
}
