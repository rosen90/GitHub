#ifndef STOCKLOAD_H_
#define STOCKLOAD_H_

#include "Date.h"

class StockLoad
{
public:
	StockLoad(const Date = 0 , double = 0 ,double = 0);
	virtual ~StockLoad();
	double getClothesQuantity() const;
	void setClothesQuantity(double clothesQuantity);

	double getPricePerKg() const;
	void setPricePerKg(double pricePerKg);
	double loadCash();


private:
	Date loadDate;
	double clothesQuantity;
	double pricePerKg;
};

#endif
