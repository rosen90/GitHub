#include <bitset>
#include <set>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{

	srand(time(0));

	const int SIZE = 80;

	bitset<SIZE> numbers;
	bitset<SIZE> randomPicks;


	for(int i = 0; i < 10; i++)
	{
		if(numbers[1 + rand() % 80] == 1)
		{
			i--;
		}
		else
		{
			numbers[1 + rand() % 80] = 1;
		}

	}

	while (randomPicks.count() < 20)
	{
		randomPicks[1 + rand() % 80] = 1;
	}

//	for(int i = 0; i < 20; i++)
//	{
//		int temp = 1 + rand() % 80;
//		if(randomPicks[temp] == 1)
//		{
//			i--;
//		}
//		else
//		{
//			randomPicks[temp] = 1;
//		}
//	}


	int counter = 0;

	for(int i = 0; i < 80; i++)
	{
		if(randomPicks[i] == 1)
		{
			counter++;
		}
	}


//	int spots = 0;
//
//	for(int i = 0; i < 80; i++)
//	{
//		if(numbers[i] & randomPicks[i])
//		{
//			spots++;
//		}
//	}
//
	cout << randomPicks.count() << endl;
	for (int i = 0; i<SIZE; i++)
	{
		if (randomPicks[i+1] ==1)
		{
			cout << i+1 << " ";
		}
	}

 	return 0;
}
