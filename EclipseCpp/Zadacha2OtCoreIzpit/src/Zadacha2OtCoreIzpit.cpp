//Rosen Karadinev%
#include <iostream>
#include "RationalNumber.h"
using namespace std;

int main()
{
	cout << "Enter numerator for first number: ";
	int numerator1;
	cin >> numerator1;

	cout << "Enter denominator for first number: ";
	int denominator1;
	cin >> denominator1;

	cout << "Enter numerator for second number: ";
	int numerator2;
	cin >> numerator2;

	cout << "Enter denominator for second number: ";
	int denominator2;
	cin >> denominator2;

	cout << endl;

	RationalNumber num1( numerator1, denominator1 ), num2( numerator2, denominator2 ), sum;

	num1.printRational();
	cout << " + " ;
	num2.printRational();
	cout << " = ";
	sum = num1 + num2;
	sum.printRational();
	cout << endl;

	num1.printRational();
	cout << ( ( num1 == num2 ) ? "  == " : "  != " );
	num2.printRational();
	cout << " testing == operator\n";


	cout << endl;


	   return 0;
}
