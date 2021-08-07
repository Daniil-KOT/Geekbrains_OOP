#ifndef __CARD_H__ 
#define __CARD_H__

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Card
{
protected:

	enum Suit { DIAMONDS, SPADES, CLUBS, HEARTS };
	enum Value { ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13 };
	bool position_ = true;
	Value value_;
	Suit suit_;

public:

	Card();

	Card(Suit suit, Value value);

	void Flip();

	Value GetEnumValue() const;

	string GetStringSuit() const;

	string GetStringValue() const;

	bool GetPosition() const;

	int GetCardValue() const;

	friend ostream& operator <<(ostream& out, Card& card);

};
#endif // !__CARD_H__

