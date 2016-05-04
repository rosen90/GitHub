#include <iostream>
using namespace std;

bool checkMatrix(int a[][5]);
void printMatrix(int a[][5]);
void findElement(double[], int);
void printArray(double[], int);

int main()
{

	int a[5][5] = {{3,5, 2, 1, 9},
				   {0, 1, 2, 3, 4},
				   {12, 15, 16, 17, 18},
				   {0, 3, 6, 9, 12},
				   {5, 3, 4, 2, 1}};

	printMatrix(a);
	if (checkMatrix(a) == true)
	{
		cout << "At least one row with a[i][j] = i*j -> true" << endl;
	}
	else
	{
		cout << "At least one row with a[i][j] = i*j -> false" << endl;
	}


	double arr[6] = {1.2, 1.1, 1.4, 1.5, 1.6, 1.9};

	cout << endl;
	printArray(arr, 6);
	cout << endl;
	findElement(arr, 6);


	return 0;
}


void findElement(double ar[], int len)
{
	for(int i = 1; i < len - 1; i++)
	{
		if((ar[i] + ar[i + 2]) / 2 == ar[i + 1])
		{
			cout << "The element at index " << i + 1
			<< " is = " << "(element with index " << i  << " + element of index " << i + 2 << ") / 2" << endl; // i + 1 because its start from 1 element
		}
	}
}

bool checkMatrix(int a[][5])
{
	int count = 0;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(a[i][j] == i * j)
			{
				count++;
			}
			if(count == 5)
			{
				return true;
			}
		}
	}

	return false;
}

void printMatrix(int a[][5])
{
	cout << "The matrix is: " << endl;
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cout << a[i][j] << " ";
		}

		cout << endl;
	}
}

void printArray(double ar[], int len)
{
	cout << "The array is " << endl;
	for(int i = 0; i < len; i++)
	{
		cout << i << " ";
	}
}
