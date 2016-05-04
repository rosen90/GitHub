//Create a class called Employee that includes three pieces
//of information as data membersa first name, a last name
//and a monthly salary. Your class should have a
//constructor that initializes the three data members.
//Provide a set and a get function for each data member. If
//the monthly salary is not positive, set it to 0. Write a test
//program that demonstrates class Employee's capabilities.
//Create two Employee objects and display each object's
//yearly salary. Then give each Employee a 10 percent
//raise and display each Employee's yearly salary again.

#include <iostream>
#include "Emloyee.h"
using namespace std;

int main()
{
	string managerFirstName;
	cout << "Manager first name: ";
	cin >> managerFirstName;

	string managerLastName;
	cout << "Manager last name: ";
	cin >> managerLastName;

	float managerSalary;
	cout << "Manager Salary: ";
	cin >> managerSalary;

	cout << "---------------" << endl;

	Employee manager(managerFirstName, managerLastName, managerSalary);
	Employee worker("Pesho", "Lainarov", 450.80);

	cout << "Manager: " << manager.getFirstName() << " " << manager.getLastName() << endl;
	cout << "Salary: " << manager.getSalary() << endl;
	cout << "Salary + 10% bonus: " << manager.getSalary() * 1.1 << endl;

	cout << endl << endl;

	cout << "Worker: " << worker.getFirstName() << " " << worker.getLastName() << endl;
	cout << "Salary: " << worker.getSalary() << endl;
	cout << "Salary + 10% bonus: " << worker.getSalary() * 1.1 << endl;

	return 0;
}
