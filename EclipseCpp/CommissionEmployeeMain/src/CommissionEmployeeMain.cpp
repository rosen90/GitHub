#include <iostream>
#include <iomanip>

using namespace std;

#include "CommissionEmployee.h"

int main()
{

	CommissionEmployee employee("Sue", "Jones", "222-22-2222", 10000, .06, 300);

	cout << fixed << setprecision(2);

	cout << "Employee information obtained by get funcitons: \n"
		<< "\nFirst name is " << employee.getFirstName()
		<< "\nLast name is " << employee.getLastName()
		<< "\nSocial security number is "
		<< employee.getSocialSecurityNumber()
		<< "\nGross sales is " << employee.getGrossSales()
		<< "\nCommission rate is " << employee.getCommissionRate()
		<< "\nBase salary is " << employee.getBaseSalary() << endl;

	employee.setBaseSalary( 1000 ); // set base salary
	employee.setGrossSales( 8000 ); // set gross sales
	employee.setCommissionRate( .1 ); // set commission rate

	cout << "\nUpdated employee information output by print function: \n"
	<< endl;
	employee.print(); // display the new employee information

	// display the employee's earnings
	cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;

	return 0;
}
