//Write a program that reads two arrays from the console
//and compares them for equality.

#include <iostream>
using namespace std;

int main()
{
	int n, m;

	cout << "Enter the size of first array: ";
	cin >> n;

	cout << "Enter the size of second array: ";
	cin >> m;

	int* firstArray = new int[n];

	int* secondArray = new int[m];


	for (int i = 0; i < n; i++)
	{
		cout << "First array element " << i << " =";
		cin >> firstArray[i];
	}

	for (int i = 0; i < n; i++)
		{
			cout << "Second array element " << i << " =";
			cin >> secondArray[i];
		}


	if(n != m)
	{
		cout << "The arrays are not equal!!";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if(firstArray[i] != secondArray[i])
			{
				cout << "The arrays are not equal!!";
				break;
			}

		}

		cout << "The arrays are equal!!";
	}

	return 0;
}
