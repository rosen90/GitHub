#include <iostream>

using namespace std;

#ifndef SAVINGACCOUNT_H_
#define SAVINGACCOUNT_H_

class SavingAccount
{
	public:
		SavingAccount(double);
		void calculateMonthlyInterest();
		static void modifyInterestRate(double);
		double getBalance() const;
		void setBalance(double);
		~SavingAccount();


	private:
		static double annualInterestRate;
		double savingsBalance;
};

#endif /* SAVINGACCOUNT_H_ */
