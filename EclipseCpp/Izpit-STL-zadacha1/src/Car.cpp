#include "Car.h"
#include <string.h>

Car::Car(int number, string carBrand, string carModel, int carYear,
		double cost, string carColor)
{
	setCarNumber(number);
	setBrand(carBrand);
	setModel(carModel);
	setYear(carYear);
	setCostPerKm(cost);
	setColor(carColor);
}


const string Car::getBrand() const
{
	return brand;
}

void Car::setBrand(string brandCar)
{
	int length = brandCar.size();
	length = (length < bLENGTH ? length : bLENGTH - 1);
	brandCar.copy(this->brand, length);
	brandCar[length] = '\0';
}

int Car::getCarNumber() const
{
	return carNumber;
}

void Car::setCarNumber(int carNumber)
{
	this->carNumber = carNumber;
}

const string Car::getColor() const
{
	return color;
}

void Car::setColor(string colorCar)
{
	int length = colorCar.size();
	length = (length < cLENGTH ? length : cLENGTH - 1);
	colorCar.copy(this->color, length);
	colorCar[length] = '\0';
}


void Car::setCostPerKm(double costPerKm)
{
	if(costPerKm > 0)
	{
		this->costPerKm = costPerKm;
	}
	else
	{
		this->costPerKm = 0;
	}

}

double Car::getCostPerKm() const
{
	return costPerKm;
}

const string Car::getModel() const
{
	return model;
}

void Car::setModel(string modelCar)
{
	int length = modelCar.size();
	length = (length < mLENGTH ? length : mLENGTH - 1);
	modelCar.copy(this->model, length);
	modelCar[length] = '\0';
}

int Car::getYear() const
{
	return year;
}

void Car::setYear(int year)
{
	if(year >= 1900 && year < 2015)
	{
		this->year = year;
	}
	else
	{
		this->year = 1900;
		cout << "Invalid year... set to 1900" << endl;
	}

}

Car::~Car()
{

}
