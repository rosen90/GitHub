//2. От входен файл се чете квадратна матрица с размери NxN. Да се изведе на
//стандартния изход всеки диагонал на матрицата както е показано на примера.
//Пример:
//1 1 2 3 1
//5 8 13 21  5 1
//34 55 89 144 34 8 2
//233 377 610 987 233 55 13 3
//377 89 21
//610 144
//987

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

void print(string[][4], int);

int main()
{
	ifstream readText("matrix.txt", ios::in);

	if(!readText)
	{
		cerr << "The file could not be opened";
		exit(1);
	}

	string arr[4][4];
	string word;

	int count;
	int i, j;

	while(readText >> word)
	{
		arr[i][j] = word;
		count++;
		j++;

		if(count == 5)
		{
			i++;
			count = 0;
		}
	}

	for(int i = 0; i < 4; i++ )
	{
		print(arr, i);
	}

	for(int i = 4; i < 7; i++)
	{
		print(arr, i);
	}


	return 0;
}


void print(string arr[][4], int sum)
{
	for(int i = 3; i >= 0; i--)
		for(int j = 3; j >= 0; j--)
			if(sum == i + j)
				cout << arr[i][j] << " ";
		cout << endl;
}

