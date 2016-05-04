/*
 * Square.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: Rosen
 */

#include "Square.h"
#include "TwoDimensionalShape.h"

Square::Square()
{


}

Square::Square(double side)
{
	setSide(side);

}

double Square::getArea()
{
	return getSide() * getSide();
}

Square::~Square() {
	// TODO Auto-generated destructor stub
}

