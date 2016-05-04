#include <iostream>
using namespace std;

int main()
{



	int size, center, width, count = 1;

	cout << "Size of the Tree: ";
	cin >> size;

	width = 2*size;
	center = width / 2;

	cout << endl;

	for	(int i = 0; i < size-1; i++)
	{
		for(int j= 0; j <= width+1; j++)
		{
			if(j <= (center - count) || j >= (center  + count + 2))
			{
				cout << " ";
			}
			else if (j == center + 1)
			{
				cout << "||";
			}
			else
			{
				cout << "o";
			}
		}
		cout << endl;
		count++;
	}

	for(int i = 0; i < width; i++)
	{
		if(i == (center+1))
		{
			cout << "||";
		}
		else
		{
			cout << " ";
		}
	}

	return 0;
}
