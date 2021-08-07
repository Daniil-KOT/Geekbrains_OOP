#include "Hand.h"

Hand::Hand() {}

Hand::Hand(Suit suit, Value value) 
	:Card::Card(suit, value)
{}

void Hand::AddCard(Card* card)
{
	hand_.push_back(card);
}

void Hand::Clear()
{
	for (int i = 0; i < hand_.size(); i++)
		delete hand_.at(i);
	hand_.clear();
}

int Hand::GetValue() const
{
	assert(hand_.size() != 0);
	int sum = 0;

	for (int i = 0; i < hand_.size(); i++)
	{
		if (hand_.at(i)->GetEnumValue() == ACE && sum + 11 < 21)
			sum += 11;
		else if (hand_.at(i)->GetPosition() == false)
			continue;
		else
			sum += hand_.at(i)->GetCardValue();
	}
	return sum;
}