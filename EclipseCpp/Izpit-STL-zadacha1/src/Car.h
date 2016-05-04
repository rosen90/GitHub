#ifndef CAR_H_
#define CAR_H_

#include <string>
#include <iostream>

using namespace std;

class Car
{

public:

	static const int bLENGTH = 30;
	static const int mLENGTH = 30;
	static const int cLENGTH = 30;

	Car(int = -1, string = "", string ="", int = 1900, double = 0.0, string = "");
	virtual ~Car();

	const string getBrand() const;
	void setBrand(string brand);

	int getCarNumber() const;
	void setCarNumber(int carNumber);

	const string getColor() const;
	void setColor(string color);

	double getCostPerKm() const;
	void setCostPerKm(double costPerKm);

	const string getModel() const;
	void setModel(string model);

	int getYear() const;
	void setYear(int year);

private:

	int carNumber;

	char brand[bLENGTH];
	char model[mLENGTH];
	int year;
	double costPerKm;
	char color[cLENGTH];

};

#endif
