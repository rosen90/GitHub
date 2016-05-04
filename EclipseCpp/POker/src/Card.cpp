/*
 * Card.cpp
 *
 *  Created on: 17.09.2014 г.
 *      Author: Kateto
 */
#include "Card.h"

#include <iostream>
using namespace std;

const char * Card::suits[5] = { "Hearts", "Diamonds", "Clubs", "Spades","None" };
const char * Card::faces[14] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
		"Eight", "Nine", "Ten", "Jack", "Queen", "King","Joker"  };

Card::Card(){

	suit = 0;
	face = 0;
	m_bIsHold = false;
}

Card::Card(int s, int f){


	suit = s;
	face = f;

	m_bIsHold = false;
}

void Card::ShowCard(){

	cout << faces[face] << " of " << suits[suit] << (m_bIsHold ? " - hold" : "") <<endl;
}

int Card::getFace() const
{
	return face;
}

void Card::setFace(int face)
{
	this->face = face;
}



int Card::getSuit() const
{
	return suit;
}

void Card::setSuit(int suit)
{
	this->suit = suit;
}
