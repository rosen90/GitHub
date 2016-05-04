//Да се направи клас описващ работник работещ на процент
//и твърда заплата. За всеки работник се съхранява информация
//за име, фамилия, егн, брой продажби, процент(комисионна) и
//заплата.
//Росен Карадинев

#include <iostream>
#include "Worker.h"
using namespace std;

int main()
{
	cout << "Enter name: ";
	string name;
	cin >> name;

	cout << "Enter Family name: ";
	string familyName;
	cin >> familyName;

	cout << "EGN: ";
	string egnNumber;
	cin >> egnNumber;

	cout << "Sales per mounth: ";
	int sales;
	cin >> sales;

	cout << "The commision is 4%(for example) per sale!" << endl;

	cout << "Salary per mounth: ";
	int salary;
	cin >> salary;

	cout << endl;
	cout << "worker 1: " << endl;
	Worker employee1(name, familyName, egnNumber, sales, salary);
	employee1.calculateSalary();
	employee1.workerInformation();

	cout << endl;
	cout << "example worker 2: " << endl;

	Worker employee2("Pesho", "Petrov", "9012452424", 45, 670);
	employee2.calculateSalary();
	employee2.workerInformation();

	return 0;
}
