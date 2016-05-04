#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_



#endif /* BANKACCOUNT_H_ */

using namespace std;

class Account
{
	private:

		int balance;

	public:

		Account(int balanceAccount)
		{
			if(balanceAccount >= 0)
			{
				balance = balanceAccount;
			}
			else
			{
				balance = 0;
				cout << "Invalid initial balance" << endl;
			}

		}

		void credit(int ammount)
		{
			if(ammount > 0)
			{
				balance = balance + ammount;
			}
			else
			{
				cout << "Invalid credit" << endl;
			}
		}

		void debit(int ammount)
		{
			if(ammount <= balance)
			{
				balance = balance - ammount;
			}
			else
			{
				cout << "Debit amount exceeded account balance." << endl;
			}
		}

		int getBalance()
		{
			return balance;
		}
};
