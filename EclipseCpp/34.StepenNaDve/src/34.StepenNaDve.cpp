#include <iostream>
using namespace std;

int main()
{

	int number = 489;
	int x;
	int counter = 1;

	while (number != 0)
	{
		x = number % 10;
		number = number/10;

		if(x == 4 || x == 8)
		{
			cout << "Number " << counter << " is power of 2" << endl;
		}
		else
		{
			cout << "Number " << counter << " isn`t power of 2" << endl;
		}
		counter++;
	}


	return 0;
}
