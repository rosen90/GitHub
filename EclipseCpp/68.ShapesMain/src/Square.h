#ifndef SQUARE_H_
#define SQUARE_H_

#include "TwoDimensionalShape.h"

using namespace std;

class Square : public TwoDimensionalShape
{
public:
	Square();
	Square(double);
	virtual double getArea();
	virtual ~Square();
};

#endif
