#include "Triangle.h"

Triangle::Triangle()
{

	height = 0;

}

Triangle::Triangle(double side, double heightTr)
{
	setSide(side);
	setHeight(heightTr);
}

double Triangle::getArea()
{
	return (getSide() * getHeight()) / 2;
}



double Triangle::getHeight() const
{
	return height;
}

void Triangle::setHeight(double height)
{
	this->height = height;
}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}
