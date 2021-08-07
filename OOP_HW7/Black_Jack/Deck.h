#ifndef __DECK_H__
#define __DECK_H__
#include "Hand.h"
#include "GenericPlayer.h"
#include <algorithm>
//Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт.Класс Deck имеет 4 метода:
//vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
//void Shuffle() - Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
//vold Deal(Hand& aHand) - метод, который раздает в руку одну карту
//void AddltionalCards(GenericPlayer& aGenerlcPlayer) - раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать

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
