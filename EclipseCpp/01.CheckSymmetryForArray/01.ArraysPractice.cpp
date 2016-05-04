#include <iostream>
using namespace std;

int main()
{
		cout << "Number of elements = ";
		int n;
		cin >> n;

		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cout <<"arr[" << i << "] = ";
			cin >> arr[i];
		}

		bool symmetric = true;
		for (int i = 0; i < (n + 1) / 2; i++)
		{
			if (arr[i] != arr[n - i - 1]) // important !!!
			{
				symmetric = false;
			}
		}

		cout << "Symmetric? " << symmetric;

		return 0;
}
