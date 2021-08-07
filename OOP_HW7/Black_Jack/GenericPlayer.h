#ifndef __GENERICPLAYER_H__
#define __GENERICPLAYER_H__

#include "Hand.h"

class GenericPlayer : public Hand
{
protected:

	string name_;

	GenericPlayer(string s_name);

public:

	virtual bool IsHitting() const = 0;

	bool IsBusted();

	void Bust();

	friend ostream& operator<<(ostream& out, GenericPlayer& player);
};

#endif // !__GENERICPLAYER_H__
