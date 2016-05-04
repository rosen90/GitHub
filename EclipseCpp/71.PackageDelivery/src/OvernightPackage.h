#ifndef OVERNIGHTPACKAGE_H_
#define OVERNIGHTPACKAGE_H_

#include <string>
#include "Package.h"

using namespace std;

class OvernightPackage : public Package
{
public:
	OvernightPackage();
	OvernightPackage(string&, string&, string&, string&, string&, string&, string&, string&,
			int, int, double, double, double);
	virtual ~OvernightPackage();
	double getFeePerOunce() const;
	void setFeePerOunce(double feePerOunce);

	double calculateCost();

private:
	double feePerOunce;
};

#endif /* OVERNIGHTPACKAGE_H_ */
