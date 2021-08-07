#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "GenericPlayer.h"

template <typename T>
T foolProtection()
{
	T i;
	cout << "Please, enter here: ";
	while (!(cin >> i) || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(9999, '\n');
		cin.sync();
		cout << "\nError! What you entered is not an expected type. Please, try again!\n\nPlease, enter here: ";
	}
	cout << endl;
	return i;
}

class Player : public GenericPlayer
{

public:

	Player(string name);

	virtual bool IsHitting() const override;

	void Win() const;

	void Lose() const;

	void Push() const;
};

#endif // !__PLAYER_H__
