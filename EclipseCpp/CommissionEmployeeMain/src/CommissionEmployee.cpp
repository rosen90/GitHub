#include "CommissionEmployee.h"
#include <iostream>
using std::cout;

// constructor
CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn,
		 double sales, double rate, double salary)
{
	firstName = first; // should validate
	lastName = last; // should validate
	socialSecurityNumber = ssn; // should validate
	setGrossSales(sales); // validate and store gores sales
	setCommissionRate(rate); //validate and store commission rate
	setBaseSalary(salary); // validate and store base salary
}

//set first name
void CommissionEmployee::setFirstName(const string &first)
{
	firstName = first; //should validate
}

string CommissionEmployee::getFirstName() const
{
	return firstName;
}

// set last name
void CommissionEmployee::setLastName(const string &last)
{
	lastName = last;
}

string CommissionEmployee::getLastName() const
{
	return lastName;
}

// set social secutiry number
void CommissionEmployee::setSocialSecurityNumber(const string &ssn)
{
	socialSecurityNumber = ssn; // should validate
}

string CommissionEmployee::getSocialSecurityNumber() const
{
	return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sales)
{
	grossSales = (sales < 0.0 ) ? 0.0 : sales;
}

double CommissionEmployee::getGrossSales() const
{
	return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate)
{
	commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
}

double CommissionEmployee::getCommissionRate() const
{
	return commissionRate;
}


// set base salary
void CommissionEmployee::setBaseSalary( double salary )
{
 baseSalary = ( salary < 0.0 ) ? 0.0 : salary;
} // end function setBaseSalary

 // return base salary
double CommissionEmployee::getBaseSalary() const
{
 return baseSalary;
} // end function


double CommissionEmployee::earnings() const
{
	return baseSalary + ( commissionRate * grossSales );
}


void CommissionEmployee::print() const
{
   cout << "commission employee: " << firstName << ' ' << lastName
      << "\nsocial security number: " << socialSecurityNumber
      << "\ngross sales: " << grossSales
      << "\ncommission rate: " << commissionRate
   	  << "\nbase salary: " << baseSalary;
} // end function print


CommissionEmployee::~CommissionEmployee() {
	// TODO Auto-generated destructor stub
}

