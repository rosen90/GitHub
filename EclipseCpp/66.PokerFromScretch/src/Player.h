#include "Card.h"
#include <vector>


#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{

friend class Dealer;
	public:
		Player();
		virtual ~Player();
		PowerOfHands getPowerOfHand() const;
		void addCard(Card &);
		const vector<Card> getHand() const;

	private:
		vector<Card> hand;
		PowerOfHands powerOfHand;
		void setPowerOfHand();

};

#endif /* PLAYER_H_ */
