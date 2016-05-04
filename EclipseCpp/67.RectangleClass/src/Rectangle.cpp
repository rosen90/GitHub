#include "Rectangle.h"
#include <cmath>
#include <iostream>

Rectangle::Rectangle() // Default constructor;
{

}

Rectangle::Rectangle(int pointAx, int pointAy, int pointBx, int pointBy, int pointCx, int pointCy, int pointDx, int pointDy)
{
	setaX(pointAx);
	setaY(pointAy);
	setbX(pointBx);
	setbY(pointBy);
	setcX(pointCx);
	setcY(pointCy);
	setdX(pointDx);
	setdY(pointDy);

	setSideAB(pointAx, pointAy, pointBx, pointBy);
	setSideBC(pointBx, pointBy, pointCx, pointCy);
	setSideCD(pointCx, pointCy, pointDx, pointDy);
	setSideDA(pointDx, pointDy, pointAx, pointAy);

}

Rectangle::~Rectangle()
{
	// TODO Auto-generated destructor stub
}

int Rectangle::getaX() const
{
	return aX;
}

void Rectangle::setaX(int x)
{
	if(x >= 0 && x <= 20)
	{
		aX = x;
	}
	else
	{
		aX = 0;
	}

}

int Rectangle::getaY() const
{
	return aY;
}

void Rectangle::setaY(int y)
{
	if(y >= 0 && y <= 20)
	{
		aY = y;
	}
	else
	{
		aY = 0;
	}

}

int Rectangle::getbX() const
{
	return bX;
}

void Rectangle::setbX(int x)
{
	if(x >= 0 && x <= 20)
	{
		bX = x;
	}
	else
	{
		bX = 0;
	}
}

int Rectangle::getbY() const
{
	return bY;
}

void Rectangle::setbY(int y)
{
	if(y >= 0 && y <= 20)
	{
		bY = y;
	}
	else
	{
		bY = 0;
	}
}

int Rectangle::getcX() const
{
	return cX;
}

void Rectangle::setcX(int x)
{
	if(x >= 0 && x <= 20)
	{
		cX = x;
	}
	else
	{
		cX = 0;
	}
}

int Rectangle::getcY() const
{
	return cY;
}

void Rectangle::setcY(int y)
{
	if(y >= 0 && y <= 20)
	{
		cY = y;
	}
	else
	{
		cY = 0;
	}
}

int Rectangle::getdX() const
{
	return dX;
}

void Rectangle::setdX(int x)
{
	if(x >= 0 && x <= 20)
	{
		dX = x;
	}
	else
	{
		dX = 0;
	}
}

int Rectangle::getdY() const
{
	return dY;
}

void Rectangle::setdY(int y)
{
	if(y >= 0 && y <= 20)
	{
		dY = y;
	}
	else
	{
		dY = 0;
	}
}

double Rectangle::getSideAB() const
{
	return sideAB;
}

void Rectangle::setSideAB(int pointaX, int pointaY, int pointbX, int pointbY)
{
	this->sideAB = sqrt((pointbX - pointaX)*(pointbX - pointaX) + (pointbY - pointaY)*(pointbY - pointaY));
}

double Rectangle::getSideBC() const
{
	return sideBC;
}

void Rectangle::setSideBC(int pointbX, int pointbY, int pointcX, int pointcY)
{
	this->sideBC = sqrt((pointcX - pointbX)*(pointcX - pointbX) + (pointcY - pointbY)*(pointcY - pointbY));
}

double Rectangle::getSideCD() const
{
	return sideCD;
}

void Rectangle::setSideCD(int pointcX, int pointcY, int pointdX, int pointdY)
{
	this->sideCD = sqrt((pointdX - pointcX)*(pointdX - pointcX) + (pointdY - pointcY)*(pointdY - pointcY));
}

double Rectangle::getSideDA() const
{
	return sideDA;
}

void Rectangle::setSideDA(int pointdX, int pointdY, int pointaX, int pointaY)
{
	this->sideDA = sqrt((pointaX - pointdX)*(pointaX - pointdX) + (pointaY - pointdY)*(pointaY - pointdY));
}

void Rectangle::checkRectangle()
{
	if(sideAB == sideCD && sideDA == sideBC)
	{
		if(sideAB == sideDA)
		{
			cout << "The figure is square.";
		}
		else
		{
			cout << "The figure is rectangle";
		}
	}
	else
	{
		cout << "Sorry the figure is not rectangle";
	}
}

int Rectangle::length()
{
	return sideBC;
}

int Rectangle::width()
{
	return sideAB;
}

int Rectangle::perimeterOfRectangle()
{
	return (sideAB * 2) + (sideBC * 2);
}

int Rectangle::areaOfRectangle()
{
	return sideAB * sideBC;
}

void Rectangle::showResult()
{
	checkRectangle();

	cout << endl;
	cout << "SideAB = " << getSideAB() << endl;
	cout << "SideBC = " << getSideBC() << endl;
	cout << "SideCD = " << getSideCD() << endl;
	cout << "SideDA = " << getSideDA() << endl;

	cout << endl;
	cout << "Length of figure is " << length() << endl;
	cout << "Width of figure is " << width() << endl;
	cout << "Parameter of figure is " << perimeterOfRectangle() << endl;
	cout << "Area of figure is " << areaOfRectangle() << endl;
}
