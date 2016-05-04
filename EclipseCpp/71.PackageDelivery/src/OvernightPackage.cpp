/*
 * OvernightPackage.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: Rosen
 */

#include "OvernightPackage.h"

OvernightPackage::OvernightPackage()
{

}

OvernightPackage::OvernightPackage(string& name1, string& name2, string& address1,
		string& address2, string& city1, string& city2,
		string& state1, string& state2, int zip1, int zip2,
		double weight, double cost, double feePerOunce)
		: Package(name1 , name2, address1, address2, city1, city2, state1, state2,
		zip1, zip2, weight, cost)
{
	setFeePerOunce(feePerOunce);
}



OvernightPackage::~OvernightPackage() {
	// TODO Auto-generated destructor stub
}

double OvernightPackage::getFeePerOunce() const {
	return feePerOunce;
}

void OvernightPackage::setFeePerOunce(double feePerOunce) {

	if(feePerOunce > 0)
	{
		this->feePerOunce = feePerOunce;
	}
	else
	{
		this->feePerOunce = 1;
	}
}

double OvernightPackage::calculateCost()
{
	return (getWeight() * (getCostPerOunce() + feePerOunce));
}
