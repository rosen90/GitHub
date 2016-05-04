#include "Player.h"
#include <algorithm>

bool compareCards(Card first, Card second)
{
	return first.getFace() < second.getFace();
}

bool hasFlush(vector<Card> cards)
{
	Suit firstSuit = cards[0].getSuit();
	for(unsigned int card = 1; card < cards.size(); card++)
	{
		if(firstSuit != cards[card].getSuit())
		{
			return false;
		}
	}

	return true;
}

bool hasStraight(vector<Card> cards)
{
	sort(cards.begin(), cards.end(), compareCards);

	for(unsigned int card = 1; card < cards.size(); card++)
	{
		if(cards[card].getFace() - cards[card-1].getFace())
		{
			return false;
		}
	}

	return true;
}

bool hasStraightFlush(vector<Card> cards)
{
	if(hasFlush(cards) && hasStraight(cards))
	{
		return true;
	}

	return false;
}

bool hasFullHouse(vector<Card> cards) {
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[1].getFace() != cards[2].getFace()
			&& cards[2].getFace() == cards[3].getFace()
			&& cards[3].getFace() == cards[4].getFace()) {
		return true;
	}
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[1].getFace() == cards[2].getFace()
			&& cards[2].getFace() != cards[3].getFace()
			&& cards[3].getFace() == cards[4].getFace()) {
		return true;
	}
	return false;
}

bool hasFourOfAKind(vector<Card> cards)
{
	sort(cards.begin(), cards.end(), compareCards);
	if(cards[0].getFace() != cards[1].getFace())
	{
		if(cards[1].getFace() == cards[2].getFace() &&
		   cards[2].getFace() == cards[3].getFace()
		&& cards[3].getFace() == cards[4].getFace())
		{
			return true;
		}
		else if(cards[0].getFace() == cards[1].getFace() &&
				cards[1].getFace() == cards[2].getFace() &&
				cards[2].getFace() == cards[3].getFace())
		{
			return true;
		}
	}
	return false;
}

bool hasThreeOfAKind(vector<Card> cards) {
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[1].getFace() == cards[2].getFace()){
		return true;
	}
	if (cards[1].getFace() == cards[2].getFace()
			&& cards[2].getFace() == cards[3].getFace()){
		return true;
	}
	if (cards[2].getFace() == cards[3].getFace()
			&& cards[3].getFace() == cards[4].getFace()){
		return true;
	}
	return false;
}

bool hasTwoPairs(vector<Card> cards){
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[2].getFace() == cards[3].getFace()){
		return true;
	}
	if (cards[0].getFace() == cards[1].getFace()
			&& cards[3].getFace() == cards[4].getFace()){
		return true;
	}
	if (cards[1].getFace() == cards[2].getFace()
			&& cards[3].getFace() == cards[4].getFace()){
		return true;
	}
	return false;
}

bool hasOnePair(vector<Card> cards){
	sort(cards.begin(), cards.end(), compareCards);
	if (cards[0].getFace() == cards[1].getFace()
			|| cards[1].getFace() == cards[2].getFace()
		    || cards[2].getFace() == cards[3].getFace()
			|| cards[3].getFace() == cards[4].getFace()){
		return true;
	}
	return false;

}

Player::Player()
{
	this->powerOfHand = noPower;
}

void Player::addCard(Card& card)
{
	if(this -> hand.size() < 5)
	{
		this -> hand.push_back(card);
	}
	if(this -> hand.size() == 5)
	{
		this-> setPowerOfHand();
	}
}



PowerOfHands Player::getPowerOfHand() const
{
	return this -> powerOfHand;
}

const vector<Card> Player::getHand() const {
	return this->hand;
}

void Player::setPowerOfHand() {
	if (hasStraightFlush(this->hand)) {
		this->powerOfHand = StraightFlush;
	} else if (hasFourOfAKind(this->hand)){
		this->powerOfHand = FourOfAKind;
	} else if(hasFullHouse(this->hand)){
		this->powerOfHand = FullHouse;
	} else if(hasFlush(this->hand)){
		this->powerOfHand = Flush;
	} else if(hasStraight(this->hand)){
		this->powerOfHand = Straight;
	} else if(hasThreeOfAKind(this->hand)){
		this->powerOfHand = ThreeOfAKind;
	} else if(hasTwoPairs(this->hand)){
		this->powerOfHand = TwoPairs;
	} else if (hasOnePair(this->hand)) {
		this->powerOfHand = OnePair;
	} else {
		this->powerOfHand = HighCard;
	}
}

Player::~Player()
{
	// TODO Auto-generated destructor stub
}
