// Write an application to simulate the rolling of two dice. The
//application should use an object of class Random once to roll the first
//die and again to roll the second die. The sum of the two values should
//then be calculated. Each die can show an integer value from 1 to 6, so
//the sum of the values will vary from 2 to 12, with 7 being the most
//frequent sum, and 2 and 12 the least frequent. Your application should
//roll the dice 36,000,000 times. Use a one-dimensional array to tally the
//number of times each possible sum appears. Display the results in
//tabular format.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int array[11] = {0};
	int firstDie, secondDie;



	for (int i = 0; i <= 36000000; i++)
	{
		firstDie = 1 + rand() % 6;
		secondDie = 1 + rand() % 6;


		array[firstDie + secondDie - 2]++;

	}
	cout << "-------------------------------------------------"
			"----------------------------------------------" << endl;
	cout << "Sums  |";
	for(int i = 2; i <= 12; i++)
	{
		if(i >= 10)
		{
			cout << "sum  " << i << "|";
		}
		else
		{
			cout << "sum   " << i << "|";
		}

	}

	cout << endl;
	cout << "--------------------------------------------------"
			"---------------------------------------------" << endl;
	cout << "Times |";
	for (int i = 0; i < 11; i++)
	{
		cout << array[i] << "|";
	}
	cout << endl;
	cout << "----------------------------------------------"
			"-------------------------------------------------" << endl;

	return 0;
}
