#ifndef COMMISSIONEMPLOYEE_H_
#define COMMISSIONEMPLOYEE_H_

#include <string>
using std::string;

class CommissionEmployee
{

public:

	CommissionEmployee(const string &, const string &, const string &,
			 double = 0.0, double = 0.0, double = 0.0);

	void setFirstName(const string &); // set first name
	string getFirstName() const; // return first name

	void setLastName(const string &); // set last name
	string getLastName() const; //return last Name;

	void setSocialSecurityNumber(const string &); // set SSN
	string getSocialSecurityNumber() const; // return SSN

	void setGrossSales(double); // set gross sales amount
	double getGrossSales() const; // return gross sales amount

	void setCommissionRate(double); // set commision rate (percentage)
	double getCommissionRate() const; // return commission rate

	double earnings() const; //calculate earnings;
	void print() const; // print CommissionEmployee object

	void setBaseSalary(double); // set base salary
	double getBaseSalary() const; // return base salary


	virtual ~CommissionEmployee(); // destructor

private:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	double grossSales;
	double commissionRate;
	double baseSalary;





};

#endif
