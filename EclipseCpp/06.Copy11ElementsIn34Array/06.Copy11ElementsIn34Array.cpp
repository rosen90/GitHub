//d) Copy 11-element array a into the first portion of array b, which
//contains 34 elements.

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int array1[11];
	int array2[34];

	for(int i = 0; i < 11; i++)
	{
		array1[i] = rand() % 100;
	}

	for(int i = 0; i < 34; i++)
	{
		array2[i] = array1[i];
	}

	for(int i = 0; i < 34; i++)
	{
		cout << array2[i] << " ";
	}


	return 0;
}
