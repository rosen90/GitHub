#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape
{

public:
	Triangle();
	Triangle(double, double);
	virtual double getArea();
	virtual ~Triangle();
	double getHeight() const;
	void setHeight(double height);

private:
	double height;
};

#endif /* TRIANGLE_H_ */
