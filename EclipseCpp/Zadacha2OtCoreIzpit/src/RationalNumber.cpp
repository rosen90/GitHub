#include <cstdlib>
#include <iostream>
#include "RationalNumber.h"
using namespace std;


RationalNumber::RationalNumber( int n, int d )
{
   numerator = n;
   denominator = ( d > 0 ) ? d : 1;
   reduction();
}

RationalNumber RationalNumber::operator+( const RationalNumber &a )
{
   return RationalNumber(
      numerator * a.denominator + denominator * a.numerator,
      denominator * a.denominator );
}

bool RationalNumber::operator==( const RationalNumber &equalty) const
{
   return numerator == equalty.numerator && denominator == equalty.denominator;
}



void RationalNumber::printRational() const
{
   if ( numerator == 0 )
      cout << numerator;
   else if ( denominator == 1 )
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
}

void RationalNumber::reduction()
{
   int biggest, gcd = 1;  // greatest common divisor;

   biggest = ( numerator > denominator ) ? numerator : denominator;

   for ( int i = 2; i <= biggest; i++ )
   {
	   if ( numerator % i == 0 && denominator % i == 0 )
	   {
		   gcd = i;
	   }
   }


   numerator /= gcd;
   denominator /= gcd;
}

RationalNumber::~RationalNumber()
{

}

