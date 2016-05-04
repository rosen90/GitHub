//Write a program that finds the maximal sequence of
//equal elements in an array.
//– Example: {2, 1, 1, 2, 3, 3, 2, 2, 2, 1}  {2, 2, 2}.

#include <iostream>
using namespace std;

int main()
{

	int array[10] = { 2, 1, 1, 2, 3, 3, 2, 2, 2, 1};

	int sequance = 1;
	int maxSequance = 0;
	int element = 0;

	for (int i = 0; i < 10; i++)
	{
		if (array[i] == array[i + 1])
		{
			sequance++;
		}
		if (array[i] != array[i + 1])
		{
			sequance = 1;
		}
		if (sequance > maxSequance)
		{
			maxSequance = sequance;
			element = array[i];
		}
	}

	for(int i = 0; i < 10; i++)
	{
		cout << array[i] << " ";
	}

	cout << "\nThe longest sequance is " << maxSequance << " elements of " << element;

	return 0;
}
