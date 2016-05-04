// Exercise 11.10 Solution: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream> 
#include "RationalNumber.h"
using namespace std;

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber( int n, int d )
{
   numerator = n;
   denominator = ( d > 0 ) ? d : 1; // validate denominator, 1 as default
   reduction(); // invokes function reduction
} // end RationalNumber constructor

// overloaded + operator
RationalNumber RationalNumber::operator+( const RationalNumber &a ) 
{
   return RationalNumber( 
      numerator * a.denominator + denominator * a.numerator,
      denominator * a.denominator );
} // end function operator+

// overloaded - operator
RationalNumber RationalNumber::operator-( const RationalNumber &s )
{
   return RationalNumber( 
      numerator * s.denominator - denominator * s.numerator,
      denominator * s.denominator );
} // end function operator-

// overloaded * operator
RationalNumber RationalNumber::operator*( const RationalNumber &m )
{
   return RationalNumber( numerator * m.numerator,
      denominator * m.denominator );
} // end function operator*

// overloaded / operator
RationalNumber RationalNumber::operator/( const RationalNumber &d )
{
   if ( d.numerator != 0 ) // check for a zero in numerator
   {
      return RationalNumber( numerator * d.denominator,
         denominator * d.numerator );
   } // end if
   else
   {
      cout << "Divide by zero error: terminating program" << endl;
      exit( 1 ); // stdlib function
   } // end else
} // end function operator/

// overloaded < operator
bool RationalNumber::operator<( const RationalNumber &lr ) const
{
   double thisVal = static_cast< double >( numerator ) / denominator;
   double lrVal = static_cast< double >( lr.numerator ) / lr.denominator;
   return thisVal < lrVal;
} // end function operator<

// overloaded > operator
bool RationalNumber::operator>( const RationalNumber &gr ) const
{
   return gr < *this;
} // end function operator>

// overloaded <= operator
bool RationalNumber::operator<=( const RationalNumber &ler ) const
{ 
   return !( *this > ler );
} // end function operator<=

// overloaded >= operator
bool RationalNumber::operator>=( const RationalNumber &ger ) const
{
   return !( *this < ger );
} // end function operator>=

// overloaded == operator
bool RationalNumber::operator==( const RationalNumber &er ) const
{
   return numerator == er.numerator && denominator == er.denominator;
} // end function operator==

// overloaded != operator
bool RationalNumber::operator!=( const RationalNumber &ner ) const
{ 
   return !( *this == ner );
} // end function operator!=

// function printRational definition
void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
} // end function printRational

// function reduction definition
void RationalNumber::reduction()
{
   int largest, gcd = 1;  // greatest common divisor;

   largest = ( numerator > denominator ) ? numerator : denominator;

   for ( int loop = 2; loop <= largest; loop++ )
       if ( numerator % loop == 0 && denominator % loop == 0 )
          gcd = loop;

   numerator /= gcd;
   denominator /= gcd;
} // end function reduction



