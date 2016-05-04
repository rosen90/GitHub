//3. Да се преброят всички елементи с четна стойност
//намиращи се на нечетна позиция в масив от 100 елемента.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));

	int array[100];
	int count = 0;

	for(int i = 1; i < 100; i+=2)
	{
		array[i] = 1 + rand() % 100;

		if(array[i] % 2 == 0)
		{
			count++;
		}
	}

	cout << "There is " << count << " even elements that are in odd position in the array";

	return 0;
}
