#ifndef SHOP_H_
#define SHOP_H_
#include "Sales.h"
#include "CashDesk.h"
#include "Date.h"
#include "scrappingClothes.h"
#include "StockLoad.h"
class Shop {
public:
	Shop(StockLoad, Sales, scrappingClothes, CashDesk);
	virtual ~Shop();
	const scrappingClothes& getScapChloths() const;
	void setScapChloths(const scrappingClothes& scapChloths);
	const CashDesk& getShopCash() const;
	void setShopCash(const CashDesk& shopCash);
	const Sales& getShopSales() const;
	void setShopSales(const Sales& shopSales);
	const StockLoad& getShopStockLoad() const;
	void setShopStockLoad(const StockLoad& shopStockLoad);

	void printInfo();
	void printiMoney();
	void cashNow();
	void saleInfo();
	void cashAfterSale();

private:
	StockLoad shopStockLoad;
	Sales shopSales;
	scrappingClothes scapChloths;
	CashDesk shopCash;
};

#endif
