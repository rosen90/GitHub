// Consider a two-by-three integer array t.
//a) Write a statement that declares and creates t.
//b) Write access expressions for all the elements in row 1 of t.
//c) Write access expressions for all the elements in column 2 of t.
//d) Write a nested for statement that initializes each element of t to
//zero.
//e) Write a series of statements that determines and displays the
//smallest value in t.
//f) Write a single printf statement that displays the elements of the
//first row of t.
//g) Write a statement that totals the elements of the third column of t.
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{


	int t[2][3];

	for(int row = 0; row < 2; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			t[row][col] = rand() % 20;
		}
	}

	for(int row = 0; row < 1; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			cout << t[row][col] << " ";
		}
	}



	return 0;
}
