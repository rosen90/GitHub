//Създайте 2мерен масив 10на10, запълнете го с произволни числа от 1 до 20,
//изведете всички нечетни числа на 2ричният диагонал, тяхната сума, тяхният
//брой и средната им стойност.

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int array[10][10];
	int counter = 0, sum=0;
	float average = 0;

	for(int row = 0; row < 10; row++)
	{
		for(int col = 0; col < 10; col++)
		{
			array[row][col] = rand() % 20;
		}
	}


	for(int row = 0; row < 10; row++)
		{
			for(int col = 0; col < 10; col++)
			{
				if(row+col == 9)
				{
					if(array[row][col] % 2 !=0)
					{
						cout << array[row][col] << " ";
						counter++;
						sum += array[row][col];
					}
				}
			}
		}

	average = (float)sum / (float)counter;

	cout << "\nThe sum is: " << sum << endl;
	cout << "Average: " << average << endl;


	return 0;
}
