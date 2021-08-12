#include "House.h"

House::House(string name)
	:GenericPlayer(name) {}

bool House::IsHitting() const
{
	return this->GetValue() < 16;
}

void House::FlipFirstCard()
{
	this->hand_.at(0)->Flip();
}
