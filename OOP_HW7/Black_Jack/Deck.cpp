#include "Deck.h"

Deck::Deck()
{
	this->hand_.reserve(52);
	Populate();
}

void Deck::Populate()
{
	Clear();
	for (int i = DIAMONDS; i <= HEARTS; i++)
		for (int j = ACE; j <= KING; j++)
			this->AddCard(new Card(static_cast<Suit>(i), static_cast<Value>(j)));
}

void Deck::Shuffle()
{
	random_shuffle(this->hand_.begin(), this->hand_.end());
}

void Deck::Deal(Hand& hand)
{
	if (this->hand_.empty() == false)
	{
		hand.AddCard(this->hand_.back());
		this->hand_.pop_back();
	}
	else
	{
		cout << "Deck is empty. Unable to deal." << endl;
	}
}

void Deck::DealAdditionalCards(GenericPlayer& player)
{
	cout << endl;

	while (player.IsBusted() == false && player.IsHitting())
	{
		Deal(player);
		cout << player << endl;

		if (player.IsBusted())
		{
			player.Bust();
		}
	}
}
