#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int box[5][5];


	int sum = 1;

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j <5; j++)
		{
			box[i][j] = sum;
			sum++;
		}

	}

	for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j <5; j++)
			{
				cout << box[i][j];
			}
			cout << endl;
		}

	cout << endl;

	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j <5; j++)
		{
			if(i == j)
			{
				cout << box[i][j];
			}
			else
			{
				cout << " ";
			}
		}

		cout << endl;
	}


	return 0;
}
