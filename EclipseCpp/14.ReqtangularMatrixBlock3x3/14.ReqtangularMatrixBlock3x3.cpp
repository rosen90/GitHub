//Write a program that reads a rectangular matrix of size
//N x M and finds in it the square 3 x 3 that has maximal
//sum of its elements.

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

	int n, m;

	int bestSum = 0;
	int bestRow = 0;
	int bestCol = 0;

	cout << "Enter the matrix rows: ";
	cin >> n;

	cout << "Enter the matrix cols: ";
	cin >> m;

	int matrix[n][m];

	for (int rows = 0; rows < n; rows++)
	{
		for (int cols = 0; cols < m; cols++)
		{
			matrix[rows][cols] = 1 + rand() % 21;
		}
	}

	for (int rows = 0; rows < n - 2; rows++)
	{
		for (int cols = 0; cols < m - 2; cols++)
		{
			int sum = matrix[rows][cols] + matrix[rows][cols + 1] + matrix[rows][cols + 2]
					+ matrix[rows + 1][cols] + matrix[rows + 1][cols + 1] + matrix[rows + 1][cols + 2];
			if (sum > bestSum)
			{
				bestSum = sum;
				bestRow = rows;
				bestCol = cols;
			}
		}
	}

	cout << "The best platform is:" << endl;
	cout <<  matrix[bestRow][bestCol] <<" "<< matrix[bestRow][bestCol + 1] << " " << matrix[bestRow][bestCol +2] << endl;
	cout <<  matrix[bestRow + 1][bestCol] <<" "<< matrix[bestRow + 1][bestCol + 1] << " " << matrix[bestRow + 1][bestCol + 2] << endl;
	cout << "The maximal sum is: "<< bestSum;

	return 0;
}
