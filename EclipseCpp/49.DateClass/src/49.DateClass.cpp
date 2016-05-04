//Create a class called Date that includes three pieces of
//information as data membersa month, a day and a year.
//Your class should have a constructor with three
//parameters that uses the parameters to initialize the
//three data members. For the purpose of this exercise,
//assume that the values provided for the year and day are
//correct, but ensure that the month value is in the range
//112; if it is not, set the month to 1. Provide a set and a get
//function for each data member. Provide a member
//function displayDate that displays the month, day and
//year separated by forward slashes (/). Write a test
//program that demonstrates class Date's capabilities.
#include <iostream>
#include "Date.h"
using namespace std;

int main()
{

	int setDay;
	cout << "Day: ";
	cin >> setDay;
	int setMonth;
	cout << "Month: ";
	cin >> setMonth;
	int setYear;
	cout << "Year: ";
	cin >> setYear;

	Date setDate (setDay, setMonth, setYear);

	cout << "----------" << endl;
	setDate.displayDate();

	return 0;
}
