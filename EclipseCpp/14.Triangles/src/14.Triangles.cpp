#include <iostream>
#include <math.h>
using namespace std;

int main()
{

	int a, b, c, pl, P, S;

	cout << "Enter triangle side a: ";
	cin >> a;

	cout << "Enter triangle side b: ";
	cin >> b;

	cout << "Enter triangle side c: ";
	cin >> c;


	if((a < 0 || b < 0 || c < 0) || (a > b + c || b > a + c || c > a + b))
	{
		cout << "The triangle could not exist";
	}
	else
	{
		if((a == b) && (b == c))
		{
			cout << "Ravnostranen" << endl;
		}
		else if((a == b) || (b == c) || (a == c))
		{
			cout << "Ravnobedren" << endl;
		}
		else if((a != b) && (b != c) && (a != c))
		{
			cout << "Raznostranen" << endl;;
		}
	}

	if((c*c) ==  (a*a) + (b*b))
	{
		cout << "Pravougylen" << endl;
	}

	pl = (a + b + c)/2;
	P = a + b + c;

	S = sqrt(pl*(pl-a)*(pl-b)*(pl-c));


	cout << "Perimetyr P: " << P << endl;
	cout << "Lice S: " << S << endl;




	return 0;
}
