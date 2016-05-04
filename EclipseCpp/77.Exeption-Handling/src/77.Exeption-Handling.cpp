//1. Write a conditional expression that returns either a
//double or an int. Provide an int catch handler and a
//double catch handler. Show that only the double
//catch handler executes, regardless of whether the int
//or the double is returned.

#include <iostream>

using namespace std;

#include "DivideByZeroException.h"


// perform division and throw DivideByZeroException object if
// divide-by-zero exception occurs
double quotient(int numerator, int denominator)
{
	// throw DivideByZeroException if trying to divide by zero
	if(denominator == 0)
	{
		throw DivideByZeroException();
	}

	return static_cast<double>(numerator) /  denominator;
}


int main()
{
	int number1;
	int number2;
	double result;

	cout << "Enter two integers (end-of-file to end): ";

	while(cin >> number1 >> number2)
	{
		// try block contains code that might throw exception
		// and code that should not execute if an exception occurs
		try
		{
			result = quotient(number1, number2);
			cout << "The quotient is: " << result << endl;
		}
		catch(DivideByZeroException &divideByZeroException)
		{
			cout << "Exeption occurred: "
				<< divideByZeroException.what() << endl;
		}

		cout << "\nEnter two integers (end-of-file to end): ";
	}

	cout << endl;

	return 0;
}
