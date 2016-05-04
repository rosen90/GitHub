#include <iostream>
using namespace std;

int main()
{
	char action;
	int fNum, sNum;
	int result;

	cout << "What action you want to take (+, -, *, /): ";
	cin >> action;

	cout << "Enter first number: ";
	cin >> fNum;

	cout << "Enter first number: ";
	cin >> sNum;

	if(action == '+')
	{
		result = fNum + sNum;
	}
	else if(action == '-')
	{
		result = fNum - sNum;
	}
	else if(action == '*')
	{
		result = fNum * sNum;
	}
	else if(action == '/')
	{
		result = fNum / sNum;
	}

	cout << "The answer is " << result;


	return 0;
}
