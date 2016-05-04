#ifndef DECKOFCARDS_H_
#define DECKOFCARDS_H_

#include <iostream>

class DeckOfCards
{

public:
	DeckOfCards(); // constructor
	void shuffle(); // shuffles the cards in deck
	void deal(); // deal the cards;
	void printDeck();
	void pickHand();

private:
	int deck[4][13];
	int hand[4];

};

#endif /* DECKOFCARDS_H_ */
