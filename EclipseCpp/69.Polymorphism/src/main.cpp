// Fig. 13.10: main.cpp
// Introducing polymorphism, virtual functions and dynamic binding.
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

// include class definitions
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h" 

int main()
{

	// create base-class object
	CommissionEmployee commissionEmployee(
			"Sue", "Jones", "222-22-2222", 10000, .06);

	//create base-class pointer
	CommissionEmployee *commissionEmployeePtr = 0;

	//create derived-class object
	BasePlusCommissionEmployee basePlusCommissionEmployee(
		"Bob", "Lewis", "333-33-3333", 5000, .04, 300);

	//create derived-class pointer
	BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = 0;

	// set floating - point output formatting
	cout << fixed << setprecision(2);

	//output objects commissionEmployee and basePlusCommissionEmployee
	cout << "Print base-class and derived-class objects:\n\n";

	commissionEmployee.print();
	cout << "\n\n";
	basePlusCommissionEmployee.print();

	// aim base-class pounter at base-class object and print
	commissionEmployeePtr = &commissionEmployee; // perfectly natural
	cout << "\n\n\nCalling print with base-class pointer to "
		<< "\nbase-class object invokes base-class print funciton\n\n";
	commissionEmployeePtr->print(); //invokes base-class print function

	//aim derived-class pointer at derived-class object and print
	basePlusCommissionEmployeePtr = &basePlusCommissionEmployee; // natural
	cout << "\n\n\nCalling print with derived-class pointer to "
		<< "\nderived-class object invokes derived-class "
		<< "print function: \n\n";
	basePlusCommissionEmployeePtr->print();

	//aim base-class pointer at derived-class object and print
	commissionEmployeePtr = &basePlusCommissionEmployee;
	cout << "\n\n\nCalling print with base-class pointer to "
		<< "derived-class object\ninvokes base-class print "
		<< "function on that derived-class object:\n\n";
	commissionEmployeePtr->print();
	cout << endl;


	return 0;
} // end main
