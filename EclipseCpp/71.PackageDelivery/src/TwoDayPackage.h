#ifndef TWODAYPACKAGE_H_
#define TWODAYPACKAGE_H_

#include "Package.h"

using namespace std;

class TwoDayPackage : public Package
{
public:
	TwoDayPackage();
	TwoDayPackage(string&, string&, string&, string&, string&, string&, string&, string&,
			int, int, double, double, double);  // v deteto s referenciq
	virtual ~TwoDayPackage();
	double getFlatFee() const;
	void setFlatFee(double flatFee);

	double calculateCost();

private:
	double flatFee;
};

#endif
