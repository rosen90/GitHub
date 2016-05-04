#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "TwoDimensionalShape.h"
using namespace std;

int main()
{

	Circle c;
	Square s;

	Shape *object1	= &c;
	Shape *object2 = &s;

	double radius = 6.7;
	double side = 8;
	object1->setSide(radius);       // this is polymorphism
	object2->setSide(side);

	cout << "The area of object1 which is circle is " << c.getArea() << endl;
	cout << "The area of object1 witch is square is " << s.getArea() << endl;

	return 0;
}
