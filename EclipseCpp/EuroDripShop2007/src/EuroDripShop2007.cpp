#include <iostream>
#include "CashDesk.h"
#include "Date.h"
#include "scrappingClothes.h"
#include "StockLoad.h"
#include "Shop.h"
using namespace std;

int main()
{

	Date dneshnaData(8,22,2014);
	StockLoad stock1(dneshnaData, 50.0, 2.50);
	Sales prodajba(dneshnaData, 2.68, 20.0);
	scrappingClothes scrap(30.0);
	CashDesk parata(600.0);

	Shop magazin(stock1, prodajba, scrap, parata);

	cout<<"Todey: ";
	dneshnaData.print();
	cout << endl;
	magazin.printiMoney();
	magazin.printInfo();
	magazin.cashNow();
	magazin.saleInfo();
	magazin.cashAfterSale();




	return 0;
}
