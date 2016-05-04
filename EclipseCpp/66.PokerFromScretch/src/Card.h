#include "Enumeration.h"

using namespace std;

#ifndef CARD_H_
#define CARD_H_

class Card {
	public:
		Card();
		Card(Suit, Face);
		virtual ~Card();
		Face getFace() const;
		void setFace(Face);
		Suit getSuit() const;
		void setSuit(Suit);

	private:
		Suit suit;
		Face face;
};

#endif /* CARD_H_ */
