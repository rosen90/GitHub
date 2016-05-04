#include <iostream>
using namespace std;

namespace access
{

const int number = 5;

}


int main()
{

	const int num = 10;
	int *maxPtr = const_cast< int * >(&access::number);
	maxPtr = const_cast<int *>(&num);
	cout << *maxPtr;

	return 0;
}
