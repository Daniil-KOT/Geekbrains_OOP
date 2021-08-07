#ifndef __HAND_H__
#define __HAND_H__
#include "Card.h"

class Hand : public Card
{
protected:

	vector<Card*> hand_;

public:

	Hand();

	Hand(Suit suit, Value value);

	void AddCard(Card* card);

	void Clear();

	int GetValue() const;
};

#endif // !__HAND_H__

