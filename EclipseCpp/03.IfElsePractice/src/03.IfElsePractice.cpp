#include <iostream>
using namespace std;

int main()
{

	int fNum, sNum, temp;

	cout << "First Number: ";
	cin >> fNum;

	cout << "Second Number: ";
	cin >> sNum;

	if (fNum > sNum)
	{
		temp = fNum;
		fNum = sNum;
		sNum = temp;

		cout << "First number: " << fNum << endl;
		cout << "Second number: " << sNum << endl;
	}
	else
	{
		cout << "no exchange is needed";
	}



	return 0;
}
