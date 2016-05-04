#include "CashDesk.h"

CashDesk::CashDesk(double cash) {
setCash(cash);
}

CashDesk::~CashDesk()
{

}

double CashDesk::getCash() const {
	return cash;
}

void CashDesk::setCash(double cash) {
	if (cash > 0 ){
		this->cash = cash;
	}else {
		this->cash = 0;
	}

}
