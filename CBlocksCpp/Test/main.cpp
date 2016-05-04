//this was created because of someone else's
//keno code from Planet-Source-Code.com
//the idea was cool, but the code needed to be
//improved, I'm going to do it
//
//created 02/05/01

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
//---PROTOTYPES---

void genNumbers(int, int *);
void numSelect(int, int [], int *);
void numCompare(int [], int [], int, int *);

//---GLOBALS---

const int MAX = 55;
const int TAB = 25;

//---MAIN PROGRAM---
int main()
{

	//variables

	int money = 2000;
	int *loot = NULL;
	bool flag = 1;
	char play = ' ';

	loot = &money;

	cout << setw(MAX) << "Welcome to a Cheesy Keno Game!!!\n\n";

	cout << "The Rules:\n";
	cout << "You start with $2000.  Each number you pick will cost you $20.\n";
	cout << "You will get $50 for each correctly chosen number.\n";
	cout << "The game ends when you either quit or run out of money.\n";
	cout << "Good Luck!!!\n\n";

	do
	{

		int numSpots = 0;

		cout << "\nYour current balance is: $" << *loot << endl;

		cout << "How many numbers (1-10) do you want to pick? ";
		cin >> numSpots;

		//insert here

		genNumbers(numSpots, loot);

		if(money == 0)
			cout << "Sorry my friend, you just ran out of money.\n";

		else if(money < 0)
		{

			cout << "Sorry my friend, you just ran out of money.\n";
			cout << "Now you owe us money!!!\n";

		}

		else
		{

			cout << "Do you want to play again? (Y/N): ";
			cin >> play;

			if(toupper(play) == 'N')
				flag = 0;
			else
				flag = 1;

		}

	}while(flag);

}//end main


//---FUNCTION DEFINITIONS---

void genNumbers(int numChoice, int *green)
{

	int randNums[10] = {0};
	int i = 0;

	srand(time(NULL));  //<---needed for rand num gen

	do
	{

		randNums[i] = 1 + rand() % (80 - 1 + 1); //<--- random number generator, gen num from 1-80
		i++;

	}while(i < numChoice);

	//for(int k = 0; k < numChoice; k++)  //<--- prints the random numbers
	//	cout << randNums[k] << endl;

	numSelect(numChoice, randNums, green);

}//end genNumbers

void numSelect(int userNum, int genNums[10], int *dollars)
{

	int userPick[10] = {0};
	int k = 0;

	cout << "\nPick your " << userNum << " numbers.\n";

	cout << "Number " << k+1 << " : ";
	cin >> userPick[k];

	for(k = 1; k < userNum; k++)
	{

		cout << "Number " << k+1 << " : ";
		cin >> userPick[k];

	}

	numCompare(userPick, genNums, userNum, dollars);

}//end numSelect

void numCompare(int inputNum[10], int compGen[10], int numPicks, int *benjamins)
{

	int correct = 0;
	int rightPct = 0;
	float x = 0;

	//nested for loops to compare generated nums to user nums
	for(int i = 0; i < numPicks; i++)
	{

		for(int j = 0; j < numPicks; j++)
		{

			if(inputNum[i] == compGen[j])
				correct++;

		}

	}

	cout << "\nYour picks" << setw(TAB) << "Computer's picks\n";
	cout << "----------" << setw(TAB) << "----------------\n";

	for(int k = 0; k < numPicks; k++)
		cout << inputNum[k] << setw(TAB) << compGen[k] << endl;

	cout << "\nYou got " << correct << " guesses right.";

	x = float(correct) / float(numPicks);  //takes the percentage of correct guesses
	rightPct = (int)floor(x * 10);		   //converts it to a whole number

	switch(rightPct)
	{

	case 0: case 1: case 2:
		cout << "\nGeez, that's not so good.  Better try again.\n\n";
		break;

	case 3: case 4: case 5:
		cout << "\nYou're getting there.  Try harder next time though.\n\n";
		break;

	case 6: case 7: case 8:
		cout << "\nThat was pretty good!  You must play this a lot!\n\n";
		break;

	case 9: case 10:
		cout << "\nWow!!!  You should go to Las Vegas!!!\n\n";
		break;

	default:
		break;

	};

	*benjamins -= (20 * numPicks);
	*benjamins += (50 * correct);

	cout << "You have $" << *benjamins << " left.\n";

}
