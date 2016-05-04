//5. Write a function that displays at the the screen a  solid
//square  of  asterisks  whose  side  is specified in integer
//parameter side.

#include <iostream>
using namespace std;

void printSquare(int parameter)
{
	for(int i = 0; i < parameter/4; i++)
	{
		for(int j = 0; j < parameter/4; j++)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}
}

int main()
{

	int parameter;
	cout << "Parameter: ";
	cin >> parameter;

	cout << endl;

	printSquare(parameter);
	return 0;
}
