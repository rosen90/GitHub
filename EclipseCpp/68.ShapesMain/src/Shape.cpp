#include <iostream>
#include "Shape.h"

Shape::Shape() //default
{
	this->side = 0;
}

Shape::Shape(double figureSide) // overload constructor
{
	setSide(figureSide);
}


double Shape::getSide() const
{
	return side;
}

void Shape::setSide(double &side)
{
	if(side > 0)
	{
		this->side = side;
	}
	else
	{
		this->side = 0;
	}

}

Shape::~Shape() {

}
