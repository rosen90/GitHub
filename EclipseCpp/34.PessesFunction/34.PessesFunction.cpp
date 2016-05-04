//4. Write a program that inputs a series of integers
//and passes them one at a time to function even, which
//uses the modulus operator to determine whether an integer
//is even. The function should take an integer argument and
//return true if the integer is even and false otherwise.

#include <iostream>
using namespace std;

bool check(int number)
{
	if(number % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void numbers(int size)
{
	int sequance[size];

	for(int i = 0; i < size; i++)
	{
		cout << "Enter " << i+1 << " number: ";
		cin >> sequance[i];

		cout << boolalpha << check(sequance[i])  << endl;

	}


}

int main()
{

	int size;
	cout << "How many numbers you want to check: ";
	cin >> size;

	numbers(size);

	return 0;
}
