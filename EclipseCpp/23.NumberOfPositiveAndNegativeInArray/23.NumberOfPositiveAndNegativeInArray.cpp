//9. Даден е масив A[n]; намерете броя на положителните и броя на отрицателните елементи

#include <iostream>
using namespace std;

int main()
{

	int array[10] = {1, -32, 54, -24, 111, -5, -3, 22, 7, 21};
	int positiveCount = 0, negativeCount = 0;

	for(int i = 0; i < 10; i++)
	{
		if(array[i] > 0)
		{
			positiveCount++;
		}
		else
		{
			negativeCount++;
		}
	}

	cout << "Positive elements: " << positiveCount << endl;
	cout << "Negative elements: " << negativeCount << endl;

	return 0;
}
