#ifndef RECTANGLE_H_
#define RECTANGLE_H_

using namespace std;

class Rectangle
{

public:
	Rectangle();
	Rectangle(int, int, int, int, int, int, int, int);
	virtual ~Rectangle();

	int length();
	int width();
	int perimeterOfRectangle();
	int areaOfRectangle();
	void checkRectangle();
	void showResult();

	int getaX() const;
	void setaX(int);
	int getaY() const;
	void setaY(int);
	int getbX() const;
	void setbX(int);
	int getbY() const;
	void setbY(int);
	int getcX() const;
	void setcX(int);
	int getcY() const;
	void setcY(int);
	int getdX() const;
	void setdX(int);
	int getdY() const;
	void setdY(int);

	double getSideAB() const;
	void setSideAB(int, int, int, int);
	double getSideBC() const;
	void setSideBC(int, int, int, int);
	double getSideCD() const;
	void setSideCD(int, int, int, int);
	double getSideDA() const;
	void setSideDA(int, int, int, int);

private:
	int aX, aY;
	int bX, bY;
	int cX, cY;
	int dX, dY;

	double sideAB;
	double sideBC;
	double sideCD;
	double sideDA;

};

#endif /* RECTANGLE_H_ */
