#include "Dealer.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>
Dealer::Dealer() {
	// TODO Auto-generated constructor stub

}

vector<Card> Dealer::generateDeck()
{
	vector<Card> initialDeck;
	vector<Card> deck;
	Face currentFace;
	Suit currentSuit;

	for(int suit = 0; suit <= Spade; suit++)
	{
		for(int face = 0; face <= Ace; face++)
		{
			currentSuit = static_cast<Suit>(suit);
			currentFace = static_cast<Face>(face);
			initialDeck.push_back(Card(currentSuit, currentFace));
		}
	}

	int index;
	srand(time(0));

	while(initialDeck.size() != 0)
	{
		index = rand() % initialDeck.size();
		deck.push_back(initialDeck.at(index));
		initialDeck.erase(initialDeck.begin() + index);
	}

	return deck;
}

void Dealer::dealCard(Card& card, Player& player) {
	player.addCard(card);
}


void Dealer::shuffleDeck(vector<Card> &deck)
{
	srand(time(0));
	int firstCardIndex;
	int secondCardIndex;
	int shuffleCount = 50 + rand() % 150;

	for(int shuffle = 0; shuffle < shuffleCount; shuffle++)
	{
		firstCardIndex = rand() % deck.size();
		secondCardIndex = rand() % deck.size();
		swap(deck[firstCardIndex],deck[secondCardIndex]);
	}
}

Dealer::~Dealer() {
	// TODO Auto-generated destructor stub
}

