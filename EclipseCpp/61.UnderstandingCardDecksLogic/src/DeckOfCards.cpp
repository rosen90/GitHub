#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
	// loop through rows of deck
	for(int row = 0; row <= 3; row++)
	{
		// loop through columns of deck for current row
		for(int column = 0; column <= 12; column++)
		{
			deck[row][column] = 0; // initialize slot of deck to 0
		}
	}

	srand(time(0));
}

void DeckOfCards::printDeck()
{
	for(int row = 0; row <= 3; row++)
	{
		for(int column = 0; column <= 12; column++)
		{
			cout << deck[row][column] << " ";
		}
		cout << endl;
	}
}

void DeckOfCards::shuffle()
{
	int row;  //boqta na kartata(spatiq, karo, pika, kupa)
	int column; //liceto na kartata(dvoika, petica, Dama, Pop, Vale i tn)

	// for each of the 52 cards, choose a slot of the deck randomly
	for(int card = 1; card <= 52; card++)
	{
		do // choose a new random location until unoccupied slot
		{
			row  = rand() % 4; // randomly select the row
			column = rand() % 13; // randomly select the column

		}
		while(deck[row][column] != 0); //ako kvadrad4eto ne e 0 pak rollni random 4isla dokato ne oceli nulevo kvadad4e

		// place card number in chosen slot of deck
		deck[ row ][ column ] = card;

	}
}

void DeckOfCards::deal()
{
	// pravim masiv s boite( spatiq, karo, pika, kupa)
	static const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	//pravim masiv s licata( pop, dama, desetka, dvoika, Aso i t.n)
	static const char *face[13] =
		{"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
		"Eight", "Nine", "Ten", "Jack", "Queen", "King"};

	// for each of the 52 cards
	for(int card = 1; card <= 52; card++)
	{
		// loop through rows of deck
		for(int row = 0; row <= 3; row++)
		{
			for(int column = 0; column <= 12; column++)
			{
				if(deck[row][column] == card)
				{
					cout << setw(5) << right << face[column]
					 << " of " << setw(8) << left << suit[row]
					 << (card % 2 == 0 ? '\n' : '\t');

				}
			}
		}
	}
}

void DeckOfCards::pickHand()
{
	bool duplicate = true;

	for(int i = 0; i < 5; i++)
		hand[i] = 1 + rand() % 52;

	while(duplicate == true)
	{
		int dupCounter = 0;
		for(int i = 0; i < 5; i++)
		{
			for(int x = 0; x < 5; x++)
			{
				if(hand[i] == hand[x] && x != i)
				{
					dupCounter++;
					hand[x] =  1 + rand() % 52;
				}
			}
		}
		if(dupCounter == 0)
		{
			duplicate = false;
		}
	}

	cout << "Your hand: " << endl;


	// pravim masiv s boite( spatiq, karo, pika, kupa)
		static const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

		//pravim masiv s licata( pop, dama, desetka, dvoika, Aso i t.n)
		static const char *face[13] =
			{"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
			"Eight", "Nine", "Ten", "Jack", "Queen", "King"};

		// for each of the 52 cards
		for(int card = 0; card < 5; card++)
		{
			// loop through rows of deck
			for(int row = 0; row <= 3; row++)
			{
				for(int column = 0; column <= 12; column++)
				{
					if(deck[row][column] == hand[card])
					{
						cout <<face[column]
						 << " of "  << suit[row] << endl;

					}
				}
			}
		}
}


