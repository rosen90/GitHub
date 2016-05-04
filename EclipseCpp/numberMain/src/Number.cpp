#include <ctime>
#include <cstdlib>
#include "Number.h"



Number::Number()
{
	setNumber();
}

Number::~Number() {
	// TODO Auto-generated destructor stub
}


int Number::getNumber() const {
	return number;
}

void Number::setNumber()
{
	srand(time(0));
	this->number = 1 + rand() % 81;
}
