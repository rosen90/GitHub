#include <iostream>
#include "namespace.h"
using namespace std;

using Currency::FIVE;

int main()
{
	cout << FIVE << endl; // program one access only FIVE member


	cout << Currency::ONE << endl; // Program two can access all namespace members;


	return 0;
}
