//10. 2D масив с размери N,M ;Да се изведат нечетните
//елементи и да се намери броя на четните елементи
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int n, m, evenCounter = 0;;
	cout << "Enter n= ";
	cin >> n;

	cout << "Enter m= ";
	cin >> m;

	int array[n][m];


	for(int row = 0; row < n; row++)
	{
		for(int col = 0; col < m; col++)
		{
			array[row][col] = 1 + rand() % 100;

			if(array[row][col] % 2 != 0)
			{
				cout << array[row][col] << " ";
			}
			else
			{
				evenCounter++;
			}
		}
	}


	cout << "\nEven numbers are " << evenCounter;

	return 0;
}
