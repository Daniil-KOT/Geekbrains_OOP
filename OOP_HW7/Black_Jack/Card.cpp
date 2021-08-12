#include "Card.h"

Card::Card(){}

Card::Card(Suit suit, Value value)
	:suit_(suit), value_(value)
{}

void Card::Flip()
{
	if (position_)
		position_ = false;
	else if (!position_)
		position_ = true;
}

Card::Value Card::GetEnumValue() const
{
	return value_;
}

string Card::GetStringSuit() const
{
	switch (suit_)
	{
	case DIAMONDS:
		return "Diamonds";
		break;
	case SPADES:
		return "Spades";
		break;
	case CLUBS:
		return "Clubs";
		break;
	case HEARTS:
		return "Hearts";
		break;
	}
}

string Card::GetStringValue() const
{
	if (value_ == KING)
		return "King";
	else if (value_ == QUEEN)
		return "Queen";
	else if (value_ == JACK)
		return "Jack";
	else if (value_ == ACE)
		return "Ace";
	else
		return to_string(value_);
}

bool Card::GetPosition() const
{
	return position_;
}

int Card::GetCardValue() const
{
	if (Card::value_ == KING || value_ == QUEEN || value_ == JACK)
		return 10;
	else
		return value_;
}

ostream& operator <<(ostream& out, Card& card)
{
	if (card.position_)
		out << "Card: " << card.GetStringValue() << " of " << card.GetStringSuit();
	else
		out << "Card: XX";

	return out;
}
