#ifndef CAR_H_
#define CAR_H_

#include <string>

using namespace std;

class Car
{
public:

	Car(string = "", string = "", int = 1990, double = 0.0, string = "");
	virtual ~Car();

	const string& getCarBrand() const;
	void setCarBrand(const string& carBrand);

	const string& getCarColor() const;
	void setCarColor(const string& carColor);

	double getCarCost() const;
	void setCarCost(double carCost);

	const string& getCarModel() const;
	void setCarModel(const string& carModel);

	int getCarYear() const;
	void setCarYear(int carYear);

private:
	string carBrand;
	string carModel;
	int carYear;
	double carCost;
	string carColor;

};

#endif
