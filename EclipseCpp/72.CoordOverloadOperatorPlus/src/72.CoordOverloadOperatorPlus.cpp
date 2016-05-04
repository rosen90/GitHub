//предифиниране + за класа coord
#include <iostream>

using namespace std;

class coord
{
	int x, y; // coordinates

public:
	coord()
	{
		x = 0; y = 0;
	}

	coord(int i, int j)
	{
		x = i;
		y = j;
	}

	void get_xy(int &i, int &j)
	{
		i = x;
		j = y;
	}

	//overload na +
	coord operator+(coord object2);
};

coord coord::operator +(coord object2)
{
	coord temp;
	temp.x = x + object2.x;
	temp.y = y + object2.y;

	return temp;
}

int main()
{
	coord object1(10, 10);
	coord object2(5, 3);
	coord object3;

	int x, y;

	object3 = object1 + object2; // dobavq dva obekta izvikwa se operator+();

	object3.get_xy(x, y);
	cout << "(object1 + object2) X: " << x << ", Y: " << y << "\n";

	return 0;
}
