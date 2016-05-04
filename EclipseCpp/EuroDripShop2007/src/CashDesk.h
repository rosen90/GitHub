#include"Sales.h"
#include"scrappingClothes.h"
#include"StockLoad.h"
#ifndef CASHDESK_H_
#define CASHDESK_H_

class CashDesk
{
public:
	CashDesk(double = 0);

	virtual ~CashDesk();
	double getCash() const;
	void setCash(double cash);

private:
	double cash;


};

#endif
