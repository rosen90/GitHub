#include "Car.h"


Car::Car(string brand, string model, int year, double cost, string color)
{
	setCarBrand(brand);
	setCarModel(model);
	setCarYear(year);
	setCarCost(cost);
	setCarColor(color);
}



const string& Car::getCarBrand() const
{
	return carBrand;
}

void Car::setCarBrand(const string& carBrand)
{
	this->carBrand = carBrand;
}

const string& Car::getCarColor() const
{
	return carColor;
}

void Car::setCarColor(const string& carColor)
{
	this->carColor = carColor;
}

double Car::getCarCost() const
{
	return carCost;
}

void Car::setCarCost(double carCost)
{
	if(carCost > 0)
	{
		this->carCost = carCost;
	}
	else
	{
		carCost = 0;
	}

}

const string& Car::getCarModel() const
{
	return carModel;
}

void Car::setCarModel(const string& carModel)
{
	this->carModel = carModel;
}

int Car::getCarYear() const
{
	return carYear;
}

void Car::setCarYear(int carYear)
{
	if(carYear >= 1899 && carYear < 2015)
	{
		this->carYear = carYear;
	}
	else
	{
		this->carYear = 1990;
	}

}

Car::~Car() {
	// TODO Auto-generated destructor stub
}
