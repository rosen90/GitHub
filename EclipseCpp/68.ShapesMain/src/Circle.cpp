#include <cmath>
#include "Circle.h"
#include "TwoDimensionalShape.h"

Circle::Circle()
{


}

Circle::Circle(double radius)
{
	setSide(radius);

}

double Circle::getArea()
{
	return M_PI * (getSide() * getSide());
}

Circle::~Circle() {
	// TODO Auto-generated destructor stub
}

