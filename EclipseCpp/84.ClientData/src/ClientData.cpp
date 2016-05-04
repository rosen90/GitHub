#include <string>
using namespace std;
#include "ClientData.h"
#include "string.h"

ClientData::ClientData(int accountNumberValue,
		string lastNameValue, string firstNameValue, double balanceValue)
{
	setAccountNumber(accountNumberValue);
	setLastName(lastNameValue);
	setFirstName(firstNameValue);
	setBalance(balanceValue);
}

int ClientData::getAccountNumber() const
{
	return accountNumber;
}

void ClientData::setAccountNumber(int accountNumberValue)
{
	accountNumber = accountNumberValue;
}

string ClientData::getLastName() const
{
	return lastName;
}

void ClientData::setLastName(string lastNameString)
{
	const char *lastNameValue = lastNameString.data();
	   int length = lastNameString.size();
	   length = ( length < 15 ? length : 14 );
	   strncpy( lastName, lastNameValue, length );
	   lastName[ length ] = '\0'; // append null character to lastName
}

string ClientData::getFirstName() const
{
   return firstName;
} // end function getFirstName

// set first-name value
void ClientData::setFirstName( string firstNameString )
{
   // copy at most 10 characters from string to firstName
   const char *firstNameValue = firstNameString.data();
   int length = firstNameString.size();
   length = ( length < 10 ? length : 9 );
   strncpy( firstName, firstNameValue, length );
   firstName[ length ] = '\0'; // append null character to firstName
} // end function setFirstName

// get balance value
double ClientData::getBalance() const
{
   return balance;
} // end function getBalance

// set balance value
void ClientData::setBalance( double balanceValue )
{
   balance = balanceValue;
} // end function setBalance


ClientData::~ClientData() {
	// TODO Auto-generated destructor stub
}

