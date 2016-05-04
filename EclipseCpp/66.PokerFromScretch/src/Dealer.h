#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"
using namespace std;
#ifndef DEALER_H_
#define DEALER_H_

class Dealer
{
public:
	Dealer();
	static vector<Card> generateDeck();
	static void dealCard(Card);
	static void dealCard(Card &, Player &);
	static void shuffleDeck(vector<Card> &);
	virtual ~Dealer();
};

#endif /* DEALER_H_ */
