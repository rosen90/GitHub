//Даден е двумерен масив. Да се намери броя на
//елементите с положителна стойност във всеки ред.
//Rosen Karadinev

#include <iostream>
using namespace std;

int main()
{

	int matrix[5][5] = {{4,-12, 7, 34, -99},
						{12, -56, -123, -3, 67},
						{1, 2, 3, 4, 5,},
						{-44, -34, 45, 99, -1},
						{-2, 4, -8, 16, -32}};


	for(int row = 0; row < 5; row++)
	{
		int counter = 0;

		for(int col = 0; col < 5; col++)
		{
			if(matrix[row][col] > 0)
			{
				counter++;
				cout << matrix[row][col] << " ";
			}
			else
			{
				cout << matrix[row][col] << " ";
			}
		}
		cout << "counter: " <<  counter << " positive numbers" << endl;
	}

	return 0;
}
