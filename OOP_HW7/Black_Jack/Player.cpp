#include "Player.h"

Player::Player(string name)
	:GenericPlayer(name) {}

bool Player::IsHitting() const
{
	char answer;
	do
	{
		cout << "----------------------------------------\n\n";
		cout << this->name_ << ", would you like to take one more card? (y/n) ";
		answer = tolower(foolProtection<char>());
		if (answer == 'y')
			return true;
		else if (answer == 'n')
			return false;
		else
			cout << "Wrong input! Expected 'y' or 'n'! Try again.\n\n";
	} while (answer != 'y' && answer != 'n');
}

void Player::Win() const
{
	cout << this->name_ << " has won! Congratulations!\n\n";
}

void Player::Lose() const
{
	cout << this->name_ << " has lost! :(\n\n";
}

void Player::Push() const
{
	cout << this->name_ << ", it's a draw!\n\n";
}
