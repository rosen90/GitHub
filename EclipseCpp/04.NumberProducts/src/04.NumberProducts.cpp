#include <iostream>
using namespace std;

int main()
{
	int fNum, sNum, tNum;

		cout << "First Number: ";
		cin >> fNum;

		cout << "Second Number: ";
		cin >> sNum;

		cout << "Third Number: ";
		cin >> tNum;

		if (fNum == 0 || sNum == 0 || tNum == 0)
		        {
		            cout << "The product of the numbers is 0";
		        }
		        else
		        {
		            int counter = 0;

		            if (fNum < 0)
		            {
		                counter++;
		            }
		            if (sNum < 0)
		            {
		                counter++;
		            }
		            if (tNum < 0)
		            {
		                counter++;
		            }
		            if (counter == 1 || counter == 3)
		            {
		                cout << "The product of numbers negative(-)";
		            }
		            else
		            {
		                cout << "The product of numbers is positive(+)";
		            }
		        }
	return 0;
}
