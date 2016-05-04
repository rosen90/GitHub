#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;


class Cow
{
public:
	Cow(string name, int legs);
	Cow(const Cow&);

	string getName()
	{
		return name;
	}

	int getLegs()
	{
		return legs;
	}

private:
	string name;
	int legs;
};

Cow::Cow(string cName, int cLegs)
{
	this->name = cName;
	this->legs = cLegs;
}

Cow::Cow(const Cow& twin)
{
	this->name = twin.name;
	this->legs = twin.legs;

}

int main()
{
	Cow betsy("betsy", 4);

	Cow twinOfBetsy(betsy);

	cout << twinOfBetsy.getName();
}
