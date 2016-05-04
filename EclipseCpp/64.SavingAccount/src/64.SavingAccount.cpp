//Create a SavingsAccount class. Use a static data
//member annualInterestRate to store the annual
//interest rate for each of the savers. Each member of
//the class contains a private data member
//savingsBalance indicating the amount the saver
//currently has on deposit. Provide member function
//calculateMonthlyInterest that calculates the monthly
//interest by multiplying the balance by
//annualInterestRate divided by 12; this interest should
//be added to savingsBalance. Provide a static member
//function modifyInterestRate that sets the static
//annualInterestRate to a new value. Write a driver
//program to test class SavingsAccount.
#include <cstdlib>
#include <iostream>
#include "SavingAccount.h"
using namespace std;

int main()
{

	SavingAccount saver1(2000.00);
	SavingAccount saver2(3000.00);

	SavingAccount::modifyInterestRate(3);

	cout << "Saver 1 Savings Balance $" << saver1.getBalance() << endl;
	cout << "Saver 2 Savings Balance $" << saver2.getBalance() << endl;
	cout << endl;

	saver1.calculateMonthlyInterest();
	cout << "Saver 1 Savings Balance $" << saver1.getBalance() << endl;
	saver2.calculateMonthlyInterest();
	cout << "Saver 2 Savings Balance $" << saver2.getBalance() << endl;

	cout << endl;
	SavingAccount::modifyInterestRate(4);

	saver1.calculateMonthlyInterest();
	cout << "Saver 1 Savings Balance $" << saver1.getBalance() << endl;
	saver2.calculateMonthlyInterest();
	cout << "Saver 2 Savings Balance $" << saver2.getBalance() << endl;


	return 0;
}
