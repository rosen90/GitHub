#include <iostream>
using namespace std;
#include "Shop.h"

Shop::Shop(StockLoad stockLoad, Sales sales, scrappingClothes scrappingClothes,
		CashDesk cashDesk) {
	setShopStockLoad(stockLoad);
	setShopSales(sales);
	setScapChloths(scrappingClothes);
	setShopCash(cashDesk);

}

Shop::~Shop() {

}

const scrappingClothes& Shop::getScapChloths() const {
	return scapChloths;
}

void Shop::setScapChloths(const scrappingClothes& scapChloths) {
	this->scapChloths = scapChloths;
}

const CashDesk& Shop::getShopCash() const {
	return shopCash;
}

void Shop::setShopCash(const CashDesk& shopCash) {
	this->shopCash = shopCash;
}

const Sales& Shop::getShopSales() const {
	return shopSales;
}

void Shop::setShopSales(const Sales& shopSales) {
	this->shopSales = shopSales;
}

const StockLoad& Shop::getShopStockLoad() const {
	return shopStockLoad;
}

void Shop::setShopStockLoad(const StockLoad& shopStockLoad) {
	this->shopStockLoad = shopStockLoad;
}

void Shop::printInfo() {
	cout <<"\nThe money for loading products is: " << this->shopStockLoad.loadCash();

}

void Shop::printiMoney() {
	cout << "The base cash in shop is: " << this->shopCash.getCash();
}

void Shop::cashNow() {
	cout << "\nMoney after loading: " << this->shopCash.getCash() - shopStockLoad.loadCash();
}

void Shop::saleInfo() {
	cout << "Sales quantity: " << this->shopSales.getSaleQuantity() << endl;
	cout << "All money from sales: "
			<< this->shopSales.getSaleQuantity() * shopSales.getSalePrice();
}

void Shop::cashAfterSale() {
cout <<"\nCash in shop after sales: " << (shopCash.getCash() - shopStockLoad.loadCash())
		+ (shopSales.getSaleQuantity() * shopSales.getSalePrice());
}
