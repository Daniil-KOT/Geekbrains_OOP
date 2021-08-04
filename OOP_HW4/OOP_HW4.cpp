#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

//===============EX.1===============
//Добавить в контейнерный класс, который был написан в этом уроке, методы:
//для удаления последнего элемента массива(аналог функции pop_back() в векторах)
//для удаления первого элемента массива(аналог pop_front() в векторах)
//для сортировки массива
//для вывода на экран элементов.

#include "ArrayInt.h"

//==================================

using namespace std;

//===============EX.2===============
//Дан вектор чисел, требуется выяснить, сколько среди них различных.Постараться использовать максимально быстрый алгоритм.

vector<int> vec;

void quick_sort(vector<int>& vec, int first, int last)
{
	int i, j, x;
	i = first;
	j = last;
	x = vec[(first + last) / 2];

	do
	{
		while (vec[i] < x) i++;
		while (vec[j] > x) j--;

		if (i <= j)
		{
			swap(vec[i], vec[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (first < j)
		quick_sort(vec, first, j);
	if (i < last)
		quick_sort(vec, i, last);
}

//==================================

//===============EX.3===============
//Реализовать класс Hand, который представляет собой коллекцию карт.В классе будет одно поле : вектор указателей карт(удобно использовать вектор, т.к.это по сути динамический массив, 
//а тип его элементов должен быть - указатель на объекты класса Card).Также в классе Hand должно быть 3 метода :
//	метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
//	метод Clear, который очищает руку от карт
//	метод GetValue, который возвращает сумму очков карт руки(здесь предусмотреть возможность того, что туз может быть равен 11).


class Card
{
protected:

	enum Suit { TAMBOURINE, SPADE, CLUBS, HEARTS };
	enum Value { ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN, SIX, FIVE, FOUR, THREE, TWO };
	bool Position = false;
	Value value;
	Suit suit;


	Suit initSuit()
	{
		Suit suit = static_cast<Suit>(rand() % 3);
		return suit;
	}

	Value initValue()
	{
		Value value = static_cast<Value>(rand() % 12);
		return value;
	}

public:

	Card()
	{
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
		switch (value)
		{
		case ACE: return 1;
		case KING: return 10;
		case QUEEN: return 10;
		case JACK: return 10;
		case TEN: return 10;
		case NINE: return 9;
		case EIGHT: return 8;
		case SEVEN: return 7;
		case SIX: return 6;
		case FIVE: return 5;
		case FOUR: return 4;
		case THREE: return 3;
		case TWO: return 2;
		}
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
		hand.erase(hand.begin(), hand.end());
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

//==================================


int main()
{
	cout << "============EX.1============\n\n";

	ArrayInt array;
	for (int i = 0; i < 10; i++)
	{
		array.push_back(rand());
	}

	array.print();
	array.sort(array.getArr(), 0, array.getLength() - 1);
	array.print();

	cout << "Capacity: " << array.getCapacity() << "\n\nLength: " << array.getLength() << "\n\n";
	array.resize(20);
	cout << "Capacity: " << array.getCapacity() << "\n\nLength: " << array.getLength() << "\n\n";

	cout << array.pop_front() << "\n\n";
	cout << "Capacity: " << array.getCapacity() << "\n\nLength: " << array.getLength() << "\n\n";
	array.print();

	cout << array.pop_back() << "\n\n";
	cout << "Capacity: " << array.getCapacity() << "\n\nLength: " << array.getLength() << "\n\n";
	array.print();

	cout << "\n\n============EX.2============\n\n";

	srand(time(0));
	vec.reserve(50);

	for (int i = 0; i < vec.capacity(); i++)
		vec.push_back(rand() % 40);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	cout << "\n\n";

	quick_sort(vec, 0, vec.size() - 1);

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	cout << "\n\n";

	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	cout << vec.size();

	cout << "\n\n";

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	cout << "\n\n============EX.3============\n\n";

	Hand h;
	Card c1;
	Card c2;

	h.add(&c1);
	h.add(&c2);
	cout << h.getValue();

}
