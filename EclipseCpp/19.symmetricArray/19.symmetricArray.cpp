//5. Проверете дали даден масив е симетричен. Размерът на масива е N.
#include <iostream>
using namespace std;

int main()
{
	int n;
	bool check = true;

	cout << "Enter the size of array: ";
	cin >> n;

	int* array = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Array[" << i << "]=";
		cin >> array[i];
	}

	for(int i = 0, j = n-1; i < n/2; i++, j--)
	{
		if(array[i] != array[j])
		{
			cout << "The arrays are not symmetric";
			check = false;
			break;
		}
	}

	if(check == true)
	{
		cout << "The array is symmetric";
	}

	return 0;
}
