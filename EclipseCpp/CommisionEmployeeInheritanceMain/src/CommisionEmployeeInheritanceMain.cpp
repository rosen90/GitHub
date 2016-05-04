
#include <iostream>
#include <iomanip>

using namespace std;

#include "BasePlusCommissionEmployee.h"

int main()
{
	BasePlusCommissionEmployee employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

	cout << fixed << setprecision(2);

	cout << "Employee information obtained by get functions: \n"
		<< "\nFirst name is " << employee.getFirstName()
		<< "\nLast name is " << employee.getLastName()
		<< "\nSocial securityNumber is "
		<< employee.getSocialSecurityNumber()
		<< "\nGross Sales is " << employee.getGrossSales()
		<< "\nCommission rate is " << employee.getBaseSalary() << endl;

	employee.setBaseSalary(1000);

	cout << "\nUpdated employee information output by print function: \n" << endl;
	employee.print();

	cout << "\n\nEmployee earnings: $" << employee.earnings() << endl;

	return 0;
}
