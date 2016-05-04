#include <iostream>
#include "DeckOfCards.h"
using namespace std;

int main()
{
	DeckOfCards deck1;

	deck1.shuffle();
	deck1.printDeck();
	deck1.deal();

	cout << endl;

	deck1.pickHand();
	return 0;
}
