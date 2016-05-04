#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double root2 = sqrt(2.0); //calculate square root of 2
	int places;

	cout << "Square root of 2 with precisions 0-9." << endl
		<<"Precision set by io_base member function "
		<< "precision" << endl;

	cout << fixed; //use fixed-point notation

	//display square root using ios_base function precision
	for(places = 0; places <= 9; places++)
	{
		cout.precision(places);
		cout << root2 << endl;
	}

	cout << "\nPrecision set by stream manipulator "
		<< "setprecision:" << endl;

	//set precision for each digit, then display square root
	for(places = 0; places <=9; places++)
	{
		cout << setprecision(places) << root2 << endl;
	}

	return 0;
}
