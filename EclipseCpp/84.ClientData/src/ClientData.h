
#ifndef CLIENTDATA_H_
#define CLIENTDATA_H_

#include <string>
using namespace std;

class ClientData
{
public:
	//default ClinentData constructor
	ClientData(int = 0, string = "", string = "", double = 0.0);

	void setAccountNumber(int);
	int getAccountNumber() const;

	void setLastName(string);
	string getLastName() const;

	void setFirstName(string);
	string getFirstName() const;

	void setBalance(double);
	double getBalance() const;

	virtual ~ClientData();

private:
	int accountNumber;
	char lastName[15];
	char firstName[10];
	double balance;
};

#endif
