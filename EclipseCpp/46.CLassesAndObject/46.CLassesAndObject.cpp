//bank account

#include <iostream>
#include "bankAccount.h"
#include "Invoice.h"
using namespace std;

int main()
{
	cout << "Enter first amount: ";
	int amount;
	cin >> amount;

	Account operationOne(amount);

	cout << "Enter withdraw: ";
	int draw;
	cin >> draw;

	operationOne.debit(draw);

	cout << "After withdraw the balance is: " << operationOne.getBalance() << endl;

//	int partNumber = 15;
//	string partDescription = "lqlqlql ";
//	int quantity = 5;
//	int pricePerItem = 15;
//
//
//
//	Invoice test(partNumber, partDescription, quantity, pricePerItem);
//
//	cout << "Part Number: " << test.getPartNumber() << endl;
//	cout << "Part Description : " << test.getPartDescription() << endl;
//	cout << "Part quantity: " << test.getPartQuantity() << endl;
//	cout << "Part price : " << test.getPricePerItem() << endl;
//
//	cout << "Invoice Amount: " << test.getInvoiceAmount() << endl;



	return 0;
}
