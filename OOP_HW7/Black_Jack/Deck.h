#ifndef __DECK_H__
#define __DECK_H__
#include "Hand.h"
#include "GenericPlayer.h"
#include <algorithm>
//������� ����� Deck, ������� ��������� �� ������ Hand � ������������ ����� ������ ����.����� Deck ����� 4 ������:
//vold Populate() - ������� ����������� ������ �� 52 ����, ���������� �� ������������.
//void Shuffle() - �����, ������� ������ �����, ����� ������������ ������� �� ���������� STL random_shuffle
//vold Deal(Hand& aHand) - �����, ������� ������� � ���� ���� �����
//void AddltionalCards(GenericPlayer& aGenerlcPlayer) - ������� ������ �������������� ����� �� ��� ���, ���� �� ����� � ����� �� ��������

class Deck : public Hand
{
public:

	Deck();

	void Populate();

	void Shuffle();

	void Deal(Hand& hand);

	void DealAdditionalCards(GenericPlayer& player);
};

#endif // !__DECK_H__
