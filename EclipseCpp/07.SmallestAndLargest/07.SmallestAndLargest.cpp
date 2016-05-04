//e) Determine and display the smallest and largest values contained
//in 99-element floating-point array w.

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

	float w[99];
	float min, max;

	for(int i = 0; i < 99; i++)
	{
		w[i] = rand() % 100;
	}

	min = w[0];
	max = w[0];

	for(int i = 0; i < 99; i++)
	{
		if(w[i] < min)
		{
			min = w[i];
		}
		if(w[i] > max)
		{
			max = w[i];
		}
	}

	cout << "Min element is: " << min << endl;
	cout << "Max element is: " << max << endl;

	return 0;
}
