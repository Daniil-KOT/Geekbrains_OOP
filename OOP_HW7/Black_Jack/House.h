#ifndef __HOUSE_H__
#define __HOUSE_H__
#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:

	House(string name = "Dealer");

	virtual bool IsHitting() const override;

	void FlipFirstCard();
};

#endif // !__HOUSE_H__

