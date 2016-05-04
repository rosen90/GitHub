//3. Write a function multiple that determines for
//a pair of integers whether the second is a multiple of the first.

#include <iostream>
using namespace std;

void multiple(int a, int b)
{
	if(b % a == 0)
	{
		cout << "b is a multiple of a";
	}
	else
	{
		cout << "b is not a multiple of a";
	}
}

int main()
{

	int a, b;

	cout << "a= ";
	cin >> a;

	cout << "b= ";
	cin >> b;

	multiple(a,b);

	return 0;
}
