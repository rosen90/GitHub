//2. Write a function getMax with two parameters that
//returns the biggest of two integers. Write a program
//that reads 3 integers from the console and prints the
//largest of them using the function getMax().

#include <iostream>
using namespace std;

int getMax(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{

	int a, b, c, maxNumber;

	cout << "a= ";
	cin >> a;

	cout << "b= ";
	cin >> b;

	cout << "c= ";
	cin >> c;

	maxNumber = getMax((getMax(a,b)), c);

	cout << "The biggest number is: " << maxNumber;


	return 0;
}
