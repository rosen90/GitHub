#include <iostream>
using namespace std;

void rotate(int [][6], int, int);

int main()
{
	int matrix[6][6];
	int counter = 1;

	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			matrix[i][j] = counter;
			cout << matrix[i][j] << " ";
			counter++;
		}
		cout << endl;
	}


	cout << endl;


	return 0;
}

void rotate(int arr[][6], int row, int col)
{
	int temp[2][2];
	temp[0][0] = arr[row][col];
	temp[0][1] = arr[row][col +1];
	temp[1][0] = arr[row+1][col];
	temp[1][1] = arr[row+1][col+1];

	arr[row][col] = temp[1][0];
	arr[row][col+1] = temp[0][0];
	arr[row+1][col] = temp[1][1];
	arr[row+1][col+1] = temp[0][1];

}
