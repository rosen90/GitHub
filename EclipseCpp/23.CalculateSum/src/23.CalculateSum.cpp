#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n, x;
	cout << "Enter value for n: ";
	cin >> n;

	cout << "Enter value for x: ";
	cin >> x;

	double S = 1;
	double fact = 1;
	double powt = x;



	for (int i = 1; i <= n; i++) {
		fact *= i;
		S += fact / pow (powt, i);

	}

	cout << "S= " << S;
	return 0;
}
