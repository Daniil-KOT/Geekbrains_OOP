#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(string name)
	:name_(name)
{}

bool GenericPlayer::IsBusted()
{
	return this->GetValue() > 21;
}

void GenericPlayer::Bust()
{
	cout << this->name_ << " has an overdraw!\n\n";
}

ostream& operator<<(ostream& out, GenericPlayer& player)
{
	out << "Name: " << player.name_ << "\n\n";
	for (int i = 0; i < player.hand_.size(); i++)
		out << *player.hand_.at(i) << endl;
	out << "Sum of cards: " << player.GetValue() << endl;
	return out;
}
