#include <iostream>
using namespace std;

int main()
{
	double n, k, m;
	int result;

	cin >> n >> k >> m;

	result = n - (m+(k/2));
	cout << result;

	return 0;
}
