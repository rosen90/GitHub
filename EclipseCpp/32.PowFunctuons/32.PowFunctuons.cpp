//2. Write a function integerPower
//(base, exponent ) that returns the value of base^exponent

#include <iostream>
#include <cmath>
using namespace std;


int integerPower(int base, int exponent)
{
	int pow = base;
	for(int i = 1; i < exponent; i++)
	{
		pow *= base;
	}

	return pow;
}

int main()
{
	int number, power;

	cout << "Number= ";
	cin >> number;

	cout << "power= ";
	cin >> power;

	cout << integerPower(number, power) << endl;
	return 0;
}
