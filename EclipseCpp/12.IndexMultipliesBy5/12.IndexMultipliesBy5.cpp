//• Write a program that allocates array of 20 integers and
//initializes each element by its index multiplied by 5. Print
//the obtained array on the console.

#include <iostream>
using namespace std;

int main()
{
	int array[20];

	for(int i = 0; i < 20; i++)
	{
		array[i] = i * 5;
		cout << "Element " << i << " multiplied by 5 is " << array[i] << endl;
	}


	return 0;
}
