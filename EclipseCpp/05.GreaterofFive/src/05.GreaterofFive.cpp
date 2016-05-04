#include <iostream>
using namespace std;

int main() {

	int maxNum = 0;
	int number;

	            for (int i = 1; i < 6; i++)
	            {
	                cout << "Enter digit " << i << " to find the Max of 5 numbers: ";
	                cin >> number;

	                if (number > maxNum)
	                {
	                    maxNum = number;
	                }
	            }
	            cout << "The greatest number is " << maxNum;
	return 0;
}
