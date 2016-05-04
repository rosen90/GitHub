
#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
	Time t;

	cout << "The initial universal time is ";
	t.printUniversal();

	cout << "\nThe initial standard time is ";
	t.printStandard();

	t.setTime(15, 15, 40);

	// output Time object t's new values
	 cout << "\n\nUniversal time after setTime is ";
	 t.printUniversal();

	 cout << "\nStandard time after setTime is ";
	 t.printStandard();

	 t.setTime( 99, 99, 99 ); // attempt invalid settings

	 // output t's values after specifying invalid values
	 cout << "\n\nAfter attempting invalid settings:"
		  << "\nUniversal time: ";
	 t.printUniversal(); // 00:00:00

	 cout << "\nStandard time: ";
	 t.printStandard(); // 12:00:00 AM
	 cout << endl;

	return 0;
}
