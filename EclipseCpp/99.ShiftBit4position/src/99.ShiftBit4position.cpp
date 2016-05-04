
#include <iostream>
#include <iomanip>
using namespace std;

void displayBits( unsigned ); // prototype

int main()
{
	int number = 125;

	cout << "Before shifting: ";
	displayBits(number);

	cout << "After shifting: ";
	displayBits(number >> 4);

	return 0;
}


void displayBits( unsigned value )
{
   const int SHIFT = 4 * sizeof( unsigned ) - 1;
   const unsigned MASK = 1 << SHIFT;

   cout << value << " = ";

   for ( unsigned i = 1; i <= SHIFT + 1; i++ )
   {
      cout << ( value & MASK ? '1' : '0' );
      value <<= 1;

      if ( i % 4 == 0 )
         cout << ' ';
   }

   cout << endl;
}
