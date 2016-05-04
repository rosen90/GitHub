//11. 2D масив, 20x30, Да се намери сумата на елементите които са > K и < M
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

	srand(time(0));

	int k, m, sum = 0;

	cout << "K= ";
	cin >> k;

	cout << "M= ";
	cin >> m;

	int matrix[20][30];

	for(int row = 0; row < 20; row++)
	{
		for(int col = 0; col < 30; col++)
		{
			matrix[row][col] = 1+ rand() % 100;

			if(matrix[row][col] > k && matrix[row][col] < m)
			{
				sum += matrix[row][col];
			}
		}
	}

	cout << "The sum is " << sum;

	return 0;
}
