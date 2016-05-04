#ifndef RATIONALNUMBER_H_
#define RATIONALNUMBER_H_

class RationalNumber
{
public:
	RationalNumber(int = 0, int = 1);

	RationalNumber operator+(const RationalNumber &);

	bool operator==( const RationalNumber & ) const;

	void printRational() const;
	void reduction();

	virtual ~RationalNumber();

private:
   int numerator;
   int denominator;
};

#endif
