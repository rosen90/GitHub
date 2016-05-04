#include <iostream>
#include <vector>
#include "Dealer.h"
#include "Card.h"
#include "Enumeration.h"
#include "Player.h"

using namespace std;

string stringifyCard(Card);
string stringifyHand(PowerOfHands);

int main() {
	vector<Card> deck = Dealer::generateDeck();

	Player player;

	for (int card = 0; card < 5; ++card) {
		Dealer::dealCard(deck[deck.size() - 1],player);
		deck.erase(deck.begin() + (deck.size() - 1));
	}

	cout << "Your hand is: " << endl;
	for (unsigned int card = 0; card < player.getHand().size(); ++card) {
		cout<<stringifyCard(player.getHand().at(card))<<endl;
	}

	cout << "\nYou have: "<< endl;
	cout << stringifyHand(player.getPowerOfHand())<<endl;
	return 0;
}

string stringifyHand(PowerOfHands hand){
	string suitStr[] = {"High Card",
			"One Pair",
			"Two Pair",
			"Three Of A Kind",
			"Straight",
			"Flush",
			"Full House",
			"Four Of A Kind",
			"Straight Flush"};
	return suitStr[hand];
}

string stringifyCard(Card card){
	string result = "";

	string faceStr[] = {"Deuce", "Two", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
		"Jack", "Queen", "King", "Ace"};

	string suitStr[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

	result = faceStr[card.getFace()] + " of " + suitStr[card.getSuit()];

	return result;
}
