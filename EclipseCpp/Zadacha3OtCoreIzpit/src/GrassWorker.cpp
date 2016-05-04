
#include "GrassWorker.h"

GrassWorker::GrassWorker()
{
	this->stavka = 0;
	this->workedArea = 0;

}

GrassWorker::GrassWorker(string name, string middleName, string familyName, string EGN, string address,
		int phoneNumber, string gender, double stavka, int workedArea) : Worker(name, middleName, familyName, EGN, address, phoneNumber, gender)
{
	setStavka(stavka);
	setWorkedArea(workedArea);
}

GrassWorker::~GrassWorker() {
	// TODO Auto-generated destructor stub
}

double GrassWorker::getStavka() const {
	return stavka;
}

void GrassWorker::setStavka(double stavka) {
	this->stavka = stavka;
}

int GrassWorker::getWorkedArea() const {
	return workedArea;
}

void GrassWorker::setWorkedArea(int workedArea)
{
	this->workedArea = workedArea;
}

double GrassWorker::calculateSalary()
{
	if(workedArea < 5000)
	{
		return stavka * workedArea - 250;
	}
	if(workedArea > 10000)
	{
		return stavka * workedArea + 500;
	}

	return stavka * workedArea;

}
