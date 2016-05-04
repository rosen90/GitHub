#include "Sales.h"


Sales::Sales(const Date date, double price, double quantity) :salesDate(date)
{
	setSalePrice(price);
	setSaleQuantity(quantity);
}



double Sales::getSalePrice() const {
	return salePrice;
}

void Sales::setSalePrice(double salePrice) {

	if (salePrice > 0)
	{
		this->salePrice = salePrice;
	}
	else
	{
		this->salePrice = 0;
	}

}

const Date& Sales::getSalesDate() const {
	return salesDate;
}


Sales::~Sales() {
	// TODO Auto-generated destructor stub
}

double Sales::getSaleQuantity() const {
	return saleQuantity;
}

void Sales::setSaleQuantity(double saleQuantity) {
	if (saleQuantity > 0){
		this->saleQuantity = saleQuantity;
	}else {
		this->saleQuantity = 0;
	}

}

double Sales::cashSale() {
	return saleQuantity * salePrice;
}
