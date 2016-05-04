#include "Balance.h"
#include <iostream>
using namespace std;


Balance::Balance()
{
	this->credit = 500;
}

//Balance::Balance(int balance)
//{
//	this->credit = balance;
//}

int Balance::getCredit() const
{
	return credit;
}

void Balance::calculateWin(int spots , int catches, const int coefficient[][11])
{

	credit = credit + (coefficient[spots][catches] * 10);
}

void Balance::setCredit() {
	this->credit -= 10;
}

Balance::~Balance() {
	// TODO Auto-generated destructor stub
}


