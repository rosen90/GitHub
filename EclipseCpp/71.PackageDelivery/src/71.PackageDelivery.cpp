#include <iostream>
#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include "string.h"
#include <string>
using namespace std;

int main()
{

	string name1;
	string name2;
	string address1;
	string address2;
	string city1;
	string city2;
	string state1;
	string state2;
	int zip1;
	int zip2;

	cout << "Write information about sender ( name, address, city, state, zip code): ";
	cin >> name1 >> address1 >> city1 >> state1 >> zip1;

	cout << "Write information about reciver ( name, address, city, state, zip code): ";
	cin >> name2 >> address2 >> city2 >> state2 >> zip2;

	double weight;
	cout << "Enter weight(ounce): ";
	cin >> weight;

	double costPerOunce;
	cout << "Enter prince per ounce: ";
	cin >> costPerOunce;

	double nightCost;
	cout << "Enter for overnight package: ";
	cin >> nightCost;

	OvernightPackage paket1(name1, name2, address1, address2, city1, city2, state1, state2, zip1, zip2,
			weight, costPerOunce, nightCost);

	cout << "\nThe price is " << paket1.calculateCost();




	return 0;
}
