#ifndef SALES_H_
#define SALES_H_

#include "Date.h"

class Sales {
public:
	Sales(const Date = 0, double = 0, double = 0);
	virtual ~Sales();
	double getSalePrice() const;
	void setSalePrice(double salePrice);
	const Date& getSalesDate() const;
	double getSaleQuantity() const;
	void setSaleQuantity(double saleQuantity);
	double cashSale();
private:
	Date salesDate;
	double salePrice;
	double saleQuantity;
};

#endif
