//2.Create a class called Complex for performing arithmetic
//with complex numbers. Write a program to test your
//class. Complex numbers have the form:
//• realPart + imaginaryPart * i

#include <iostream>
#include <complex>
using namespace std;

int main()
{

	complex<double> a(3,4);
	complex<double> b(1,2);


	cout << a + b << "\n";
	return 0;
}
