#ifndef COMMISSIONEMPLOYEE_H_
#define COMMISSIONEMPLOYEE_H_

#include <string>
using namespace std;

class CommissionEmployee
{
public:
	CommissionEmployee(const string &, const string &, const string &,
			double = 0.0, double = 0.0);

	void setFirstName(const string &); // set first name
	string getFirstName() const; // return first name

	void setLastName(const string &); // set last name
	string getLastName() const; // return last name

	void setSocialSecurityNumber(const string &); // set SSN
	string getSocialSecurityNumber() const; //return ssn

	void setGrossSales(double);
	double getGrossSales() const;

	void setCommissionRate(double);
	double getCommissionRate() const;

	double earnings() const;
	void print() const;

	virtual ~CommissionEmployee();

protected:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	double grossSales;
	double commissionRate;
};

#endif
