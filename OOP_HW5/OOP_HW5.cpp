#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//=============EX.1=============
//Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.

template<typename Type>
class OneTypePair
{
	Type firstElement;
	Type secondElement;

public:

	OneTypePair(Type first, Type second)
		: firstElement(first), secondElement(second)
	{}

	Type first() const
	{
		return firstElement;
	}

	Type second() const
	{
		return secondElement;
	}

};

//==============================

//=============EX.2=============
//Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.

template<typename FirstElemType, typename SecondElemType>
class TwoTypePair
{
	FirstElemType firstElement;
	SecondElemType secondElement;

public:
	
	TwoTypePair(FirstElemType first, SecondElemType second)
		:firstElement(first), secondElement(second)
	{}

	FirstElemType first() const
	{
		return firstElement;
	}

	SecondElemType second() const
	{
		return secondElement;
	}

};

//==============================

//=============EX.3=============
//Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а второе — любого типа.
//Этот шаблон класса должен наследовать частично специализированный класс Pair, в котором первый параметр — string, а второй — любого типа данных.

template<typename Type>
class StringValuePair: public TwoTypePair<string, Type>
{
public:
	StringValuePair(string first, Type second)
		:TwoTypePair<string, Type>(first, second)
	{

	}
};

//==============================

//=============EX.4=============
//Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, который обобщенно представляет игрока, 
//ведь у нас будет два типа игроков - человек и компьютер.Создать класс GenericPlayer, в который добавить поле name - имя игрока.Также добавить 3 метода:
//IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
//IsBoosted() - возвращает bool значение, есть ли у игрока перебор
//Bust() - выводит на экран имя игрока и объявляет, что у него перебор.

class Card
{
protected:

	enum Suit { DIAMONDS, SPADES, CLUBS, HEARTS };
	enum Value { ACE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13 };
	bool Position = false;
	Value value = KING;
	Suit suit;

	Suit initSuit()
	{
		Suit suit = static_cast<Suit>(rand() % 3);
		return suit;
	}

	Value initValue()
	{
		Value value = static_cast<Value>((rand() % 12) + 1);
		return value;
	}

public:

	Card()
	{
		srand(time(0));
		value = initValue();
		suit = initSuit();
	}

	void Flip()
	{
		if (Position)
			Position = false;
		else if (!Position)
			Position = true;
	}

	Value getEnumValue() const
	{
		return value;
	}

	int getCardValue() const
	{
		if (value == KING || value == QUEEN || value == JACK)
			return 10;
		else
			return value;
	}
};

class Hand : public Card
{
	vector<Card*> hand;

public:

	void add(Card* card)
	{
		hand.push_back(card);
	}

	void clear()
	{
		for (int i = 0; i < hand.size(); i++)
			delete hand.at(i);
		hand.clear();
	}

	int getValue()
	{
		assert(hand.size() != 0);
		int sum = 0;

		for (int i = 0; i < hand.size(); i++)
		{
			if (hand.at(i)->getEnumValue() == ACE && sum + 11 < 21)
				sum += 11;
			else
				sum += hand.at(i)->getCardValue();
		}
		return sum;
	}
};

class GenericPlayer : public Hand
{
	string name;

protected:

	GenericPlayer(string s_name)
		:name(s_name)
	{}

	virtual bool isHitting() = 0;

	bool isBoosted()
	{
		if (this->getValue() > 21)
			return true;
		else
			return false;
	}

	void boost()
	{
		cout << this->name << " has an overdraw!\n\n";
	}
};

//==============================

int main()
{
	cout << "=============EX.1=============\n\n";

	OneTypePair<int> intPair(3, 7);
	cout << "Pair: " << intPair.first() << ", " << intPair.second() << "\n\n";

	OneTypePair<double> doublePair(9.3, 3.14);
	cout << "Pair: " << doublePair.first() << ", " << doublePair.second() << "\n\n";

	cout << "=============EX.2=============\n\n";

	TwoTypePair<int, double> intDoublePair(12, 2.7);
	cout << "Pair: " << intDoublePair.first() << ", " << intDoublePair.second() << "\n\n";

	TwoTypePair<double, int> doubleIntPair(9.26, 5);
	cout << "Pair: " << doubleIntPair.first() << ", " << doubleIntPair.second() << "\n\n";

	cout << "=============EX.3=============\n\n";

	StringValuePair<int> svp("Amazing", 7);
	cout << "Pair: " << svp.first() << " " << svp.second() << "\n\n" << endl;

}
