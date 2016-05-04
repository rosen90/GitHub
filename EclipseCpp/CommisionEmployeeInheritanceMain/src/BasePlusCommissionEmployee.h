
#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H_
#define BASEPLUSCOMMISSIONEMPLOYEE_H_

#include <string>
using namespace std;

#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(const string &, const string &,
		const string &, double = 0.0, double = 0.0, double = 0.0);

	void setBaseSalary(double);
	double getBaseSalary() const;

	double earnings() const;
	void print() const;

	virtual ~BasePlusCommissionEmployee();

private:
	double baseSalary;
};

#endif
