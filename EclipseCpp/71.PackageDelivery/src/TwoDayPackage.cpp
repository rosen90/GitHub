
#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage()
{
	this->flatFee = 0;
}

TwoDayPackage::TwoDayPackage(string& name1, string& name2, string& address1,
		string& address2, string& city1, string& city2,
		string& state1, string& state2, int zip1, int zip2,
		double weight, double cost, double flatFee) : Package(name1 , name2, address1, address2, city1, city2, state1, state2,
		zip1, zip2, weight, cost)
{
	setFlatFee(flatFee);
}

TwoDayPackage::~TwoDayPackage() {

}

double TwoDayPackage::getFlatFee() const {
	return flatFee;
}

void TwoDayPackage::setFlatFee(double flatFee) {

	if(flatFee > 0)
	{
		this->flatFee = flatFee;
	}
	else
	{
		this->flatFee = 0;
	}


}

double TwoDayPackage::calculateCost()
{
	return (getWeight() * getCostPerOunce()) + flatFee;
}
