//Write C++ programs to accomplish each of the following
//tasks:
//a) Display the value of element 6 of array f.

#include <iostream>
using namespace std;

int main() {

	int f[10];

	for(int i = 0; i < 10; i++)
	{
		cout << "Enter element " << i << ":";
		cin >> f[i];
	}

	cout << "The element 6 is: " << f[6];

	return 0;
}
