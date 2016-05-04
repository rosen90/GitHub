#include "TwoDimensionalShape.h"
using namespace std;

#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle : public TwoDimensionalShape
{
public:
	Circle();
	Circle(double);
	virtual double getArea();
	virtual ~Circle();

private:

};

#endif
