#ifndef TWODIMENSIONALSHAPE_H_
#define TWODIMENSIONALSHAPE_H_

#include "Shape.h"

using namespace std;

class TwoDimensionalShape : public Shape
{

public:
	TwoDimensionalShape();
	virtual double getArea() = 0; // ZADULJITELNO = 0 ZA DA STANE ABSTRAKTNA FUNKCIQ!!!


	virtual ~TwoDimensionalShape();

private:


};

#endif
