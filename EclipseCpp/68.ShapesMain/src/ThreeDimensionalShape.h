#ifndef THREEDIMENSIONALSHAPE_H_
#define THREEDIMENSIONALSHAPE_H_

#include "Shape.h"

using namespace std;

class ThreeDimensionalShape : public Shape
{
public:
	ThreeDimensionalShape();
	virtual double getArea() = 0;
	virtual double getVolume() = 0;

	virtual ~ThreeDimensionalShape();
};

#endif
