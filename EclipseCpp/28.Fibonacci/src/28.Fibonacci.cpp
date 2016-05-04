#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "How many number of Fibonachi would like to show you? :";
	cin >> n;

	long fabNum = 1;
	long fab1 = 1;
	long fab2 = 1;

	cout << "The Finonachi numbers are: 0, 1, 1";
	for (int i = 3; i < n; i++)
	{
		fabNum = fab1 + fab2;
		cout << ", " << fabNum;
		fab2 = fab1;
		fab1 = fabNum;

	}
	return 0;
}
