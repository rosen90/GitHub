#include <iostream>
#include "SavingAccount.h"

using namespace std;

double SavingAccount::annualInterestRate = 0;

SavingAccount::SavingAccount(double savingsBalance)
{
	setBalance(savingsBalance);
}

void SavingAccount::calculateMonthlyInterest()
{
	savingsBalance += ((savingsBalance * (annualInterestRate / 100)) / 12);
}

void SavingAccount::modifyInterestRate(double value)
{
	annualInterestRate = value;
}

void SavingAccount::setBalance(double savingsBalance)
{
	if(savingsBalance > 0)
	{
		this -> savingsBalance = savingsBalance;
	}
	else
	{
		this -> savingsBalance = savingsBalance;
	}
}

double SavingAccount::getBalance() const
{
	return this -> savingsBalance;
}

SavingAccount::~SavingAccount()
{

}
