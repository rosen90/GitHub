#include "Enumeration.h"
#include "Card.h"

using namespace std;

Card::Card()
{
	this->face = face;
	this->suit = suit;
}

Card::Card(Suit suit, Face face)
{
	this->face = face;
	this->suit =suit;

}


void Card::setFace(Face face)
{
	this->face = face;
}

Face Card::getFace() const
{
	return this->face;
}

void Card::setSuit(Suit suit)
{
	this->suit = suit;
}

Suit Card::getSuit() const
{
	return this->suit;
}

Card::~Card()
{

}



