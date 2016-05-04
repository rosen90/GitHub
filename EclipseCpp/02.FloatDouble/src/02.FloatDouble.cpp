#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, number;

	cout << "Enter a number: ";
	cin >> number;

	d = number % 10;
	number /= 10;
	c = number % 10;
	number /= 10;

	b = number % 10;
	number /= 10;
	a = number;

	cout << a + b + c + d << endl;
	cout << d << c << b << a << endl;
	cout << d << a << b << c << endl;
	cout << a << c << b << d << endl;

	return 0;
}
