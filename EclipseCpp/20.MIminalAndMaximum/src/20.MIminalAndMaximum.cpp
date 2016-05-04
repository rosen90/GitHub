#include <iostream>
using namespace std;

int main()
{
	int min, max, sequance;
	cout << "How many numbers you would like to enter: ";
	cin >> sequance;

	int numbers[sequance];

	for (int i = 0; i < sequance; i++)
	{
		cout << "number " << i+1 << "= ";
		cin >> numbers[i];
	}

	min = numbers[0];
	max = numbers[0];

	for(int i = 0; i < sequance; i++)
	{
		if(numbers[i] < min )
		{
			min = numbers[i];
		}
		else if(numbers[i] > max)
		{
			max = numbers[i];
		}
	}

	cout << "Min number is : " << min << endl;;
	cout << "Max number is: " << max;

	return 0;
}
