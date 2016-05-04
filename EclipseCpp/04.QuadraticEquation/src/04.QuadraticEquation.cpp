#include <iostream>
#include <math.h>
using namespace std;

int main()
{

	int a, b, c;
	double d;

			cout << "\n Quadratric Equation\n";
	        cout  << "Enter coefficient a: ";
	        cin >> a;

	        cout << "Enter coefficient b:";
	      	cin >> b;

	        cout << "Enter coefficient c:";
	        cin >> c;

	        cout << a << "x^2" << " + " << b << "x" << " + " << c << " = 0" << endl;

	        d = b * b - 4 * a * c;

	        cout << "Discriminant is: " << d << endl;

	        if (d < 0)
	        {
	            cout << "Equation has no real roots!" << endl;
	        }
	        else
	        {
	            if (d == 0)
	            {
	                cout << "Discriminant is zero so there is only one real root : x=" << ((-b) / (4 * a)) << endl;
	            }
	            else
	            {
	                cout  << "The Equation has two real roots" << endl;;
	                cout << "x1=" << ((-b + sqrt(d)) / (4 * a)) << endl;
	                cout << "x2=" << ((-b - sqrt(d)) / (4 * a)) << endl;

	            }
	        }
	return 0;
}
