#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <string>

using namespace std;

class Shape
{

public:
	Shape();
	Shape(double);
	virtual ~Shape();
	double getSide() const;
	void setSide(double &);

private:
	double side;
};

#endif
