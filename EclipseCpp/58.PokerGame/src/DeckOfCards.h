// Fig. 8.25: DeckOfCards.h
// Definition of class DeckOfCards that 
// represents a deck of playing cards.

// DeckOfCards class definition
class DeckOfCards
{
public:
   DeckOfCards(); // constructor initializes deck
   void shuffle(); // shuffles cards in deck
   void deal(); // deals cards in deck
   void playerHand();
   bool Pair();
   bool TwoPairs();
   bool ThreeOfAkind();

private:
   int hand[5];
   int deck[ 4 ][ 13 ]; // represents deck of cards
}; // end class DeckOfCards



