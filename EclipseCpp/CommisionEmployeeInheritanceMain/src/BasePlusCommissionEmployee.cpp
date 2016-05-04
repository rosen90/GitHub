
#include "BasePlusCommissionEmployee.h"
#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
		const string &first, const string &last, const string &ssn,
		double sales, double rate, double salary) : CommissionEmployee(first, last, ssn, sales, rate)
{
	setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
	return baseSalary + (commissionRate * grossSales);
}

void BasePlusCommissionEmployee::print() const
{
	cout << "Base-salaried commission employee: " << firstName << ' '
		<< lastName << "\nsocial Security number: " << socialSecurityNumber
		<< "\ngross sales: " << grossSales
		<< "\ncommission rate: " << commissionRate
		<< "\nbase salary: " << baseSalary;
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
	// TODO Auto-generated destructor stub
}

