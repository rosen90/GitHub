
#include "StockLoad.h"
#include "Date.h"

#include <iostream>
using namespace std;


StockLoad::StockLoad(Date date, double quant , double price):loadDate(date)
{
	setClothesQuantity(quant);
	setPricePerKg(price);
}

double StockLoad::getClothesQuantity() const {
	return clothesQuantity;
}

void StockLoad::setClothesQuantity(double clothesQuantity)
{
	if(clothesQuantity > 0)
	{
		this->clothesQuantity = clothesQuantity;
	}
	else
	{
		this->clothesQuantity = 0;
	}

}




StockLoad::~StockLoad() {

}

double StockLoad::getPricePerKg() const {
	return pricePerKg;
}

void StockLoad::setPricePerKg(double pricePerKg) {
	if (pricePerKg > 0){
		this->pricePerKg = pricePerKg;
	}else {
		this->pricePerKg = 0;
	}

}

double StockLoad::loadCash() {
	return pricePerKg * clothesQuantity;
}


