#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

//===========EX.1===========

//Создать класс Person(человек) с полями : имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса.
//Создать производный класс Student(студент), имеющий поле года обучения.Определить методы переназначения и увеличения этого значения.
//Создать счетчик количества созданных студентов.В функции main() создать несколько студентов.По запросу вывести определенного человека.


class Person
{
protected:
	string name = "NoName";
	int age = 0;
	string sex = "TBD";
	int weight = 0;

public:

	Person() {};

	Person(string name, int age, string sex, int weight)
		:name(name), age(age), sex(sex), weight(weight)
	{}

	void setName()
	{
		cout << "Enter your name: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, name);
	}

	void setSex()
	{
		cout << "Enter your sex: ";
		cin >> sex;
	}

	void setAge()
	{
		int age;
		cout << "Enter your age: ";
		cin >> age;

		if (age < 0)
		{
			cout << "Age cannot be less than 0!\n";
			return;
		}
		this->age = age;
	}

	void setWeight()
	{
		int weight;
		cout << "Enter your weight: ";
		cin >> weight;

		if (weight < 0)
		{
			cout << "Weight cannot be less than 0!\n";
			return;
		}
		this->weight = weight;
	}

};

class Student : public Person
{
	int yearsOfStudy = 0;

public:

	Student() {};

	Student(int yearsOfStudy)
		:yearsOfStudy(yearsOfStudy)
	{}

	void setYears()
	{
		int years;
		cout << "Enter years of study: ";
		cin >> years;

		if (years < 0)
		{
			cout << "Years of study cannot be less than 0!\n";
			return;
		}
		yearsOfStudy = years;
	}

	void yearsIncrement()
	{
		yearsOfStudy++;
	}

	void print()
	{
		cout << "Name:\t" << name << "\nAge:\t" << age << "\nWeight:\t" << weight << "\nSex:\t" << sex << "\nYears of study:\t" << yearsOfStudy << "\n\n";
	}

};

//==========================

//===========EX.2===========

//Создать классы Apple(яблоко) и Banana(банан), которые наследуют класс Fruit(фрукт).
// У Fruit есть две переменные - члена: name(имя) и color(цвет).
//Добавить новый класс GrannySmith, который наследует класс Apple.

class Fruit
{
protected:

	string name;
	string color;

public:

	string getName()
	{
		return name;
	}

	string getColor()
	{
		return color;
	}

	void print()
	{
		cout << "My " << getName() << " is " << getColor() << ".\n\n";
	}
};

class Apple : public Fruit
{
public:

	Apple()
	{
		name = "apple";
		color = "green";
	}

	Apple(string color)
	{
		name = "apple";
		Fruit::color = color;
	}

};

class Banana : public Fruit
{
public:

	Banana()
	{
		name = "banana";
		color = "yellow";
	}
	Banana(string color)
	{
		name = "banana";
		Fruit::color = color;
	}

};

class GrannySmith : public Apple
{
public:

	GrannySmith()
	{
		name = "Granny Smith apple";
		color = "green";
	}
};

//==========================

//===========EX.3===========

//Изучить правила игры в Blackjack.Подумать, как написать данную игру на С++, используя объектно - ориентированное программирование.Сколько будет классов в программе? 
//Какие классы будут базовыми, а какие производными ? Продумать реализацию игры с помощью классов и записать результаты.

class Deck
{
protected:

	static const int DECK_SIZE = 52;
	int Ace = 11;
	int King = 10;
	int Queen = 10;
	int Jack = 10;
	vector<int>deck{ Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, King, Queen, Jack,
				 Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, King, Queen, Jack,
				 Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, King, Queen, Jack,
				 Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, King, Queen, Jack };

public:

	void shuffleDeck()
	{
		srand(time(0));
		for (int i = 0; i < DECK_SIZE; i++)
		{
			swap(deck[i], deck[rand() % DECK_SIZE]);
		}
	}

	int getCard(Deck& deck)
	{
		int card = deck.deck.front();
		deck.deck.erase(deck.deck.begin());
		return card;
	}

	bool isEmpty()
	{
		return deck.empty();
	}
};

class Player : virtual public Deck
{
	vector<int>Hand;
	string name = "Dealer";

public:

	Player() {};

	Player(string name)
	{
		Player::name = name;
	}

	void hit(Deck& deck)
	{
		this->Hand.push_back(getCard(deck));
	}

	void stand()
	{
		cout << "End of your turn!\n\n";
	}

	char hitOrStand()
	{
		char choice;
		cout << "Press G to get one more card or press S to skip the turn.";
		cin >> choice;
		choice = tolower(choice);
		return choice;
	}

	int handSum()
	{
		int sum = 0;
		for (int i = 0; i < this->Hand.size(); i++)
		{
			sum+=Hand[i];
		}
		return sum;
	}

	void printHand()
	{
		cout << name <<"'s hand: ";
		for (int i = 0; i < this->Hand.size(); i++)
		{
			cout << Hand[i] << ", ";
		}
		cout << "\n\n";
	}
};

struct Game : public virtual Deck, public virtual Player
{
	bool IN_PROGRESS;

public:

	char rules()
	{
		char start;
		cout << "--------Welcome to Blackjack game!--------\n\n"
			<< "Rules:\n\n"
			<< "1. The goal is to get more PTS in your hand than in dealer's hand.\n"
			<< "2. Cards with numbers give you PTS equivalnt to their number.\nJack, Queen and King give you 10 PTS.\nAce gives you 11 PTS.\n" //(if cards in your hand + Ace are less than 21)\nor 1 PTS (if cards in your hand + Ace are more than 21)
			<< "3. If you get more than 21 PTS, it is considered to be a lose.\n"
			<< "4. Dealer cannot have less than 17 PTS in his hand.\n"
			<< "5. To start a game press B, to exit press E: ";
		cin >> start;
		start = tolower(start);
		cout << "\n";
		return start;
	}

	void distribute(Player& human, Player& dealer, Deck& deck)
	{
		human.hit(deck);
		human.hit(deck);
		dealer.hit(deck);
		dealer.hit(deck);
	}

	void checkWin(Player& human, Player& dealer)
	{
		if (human.handSum() == 21 && dealer.handSum() == 21)
			cout << "It's a draw!\n\n";
		else if (human.handSum() > 21)
			cout << "Overdraw! You have lost. :(\n\n";
		else if (dealer.handSum() > 21)
			cout << "Dealer overdraw!\nCongratulations!\nYou won!\n\n";
		else if (human.handSum() == 21 && dealer.handSum() != 21)
			cout << "Congratulations!\nYou have a Blackjack!\nYou won!\n\n";
		else if (human.handSum() != 21 && dealer.handSum() == 21)
			cout << "Dealer have a Blackjack!\nSorry, you have lost. :(\n\n";
		else if (human.handSum() > dealer.handSum())
			cout << "Congratulations!\nYou won!\n\n";
		else if (human.handSum() < dealer.handSum())
			cout << "Sorry, you have lost. :(\n\n";
		else if (human.handSum() == dealer.handSum())
			cout << "It's a draw!\n\n";
	}

	void turn(Player& human, Player& dealer, Deck& deck)
	{
		int h_Hand = human.handSum();
		char choice = ' ';

		cout << "Your turn!\n\n";
		while (choice != 's' && h_Hand < 21)
		{
			choice = human.hitOrStand();
			if (choice == 'g')
			{
				human.hit(deck);
				human.printHand();
			}
			else if (choice == 's')
				human.stand();
			else
				cout << "Wrong input! Try again.\n\n";
			h_Hand = human.handSum();
		}


		cout << "Dealer's turn!\n\n";
		while (dealer.handSum() < 17)
			dealer.hit(deck);
	}

	void start()
	{
		do
		{
			char start = rules();
			if (start == 'b')
				IN_PROGRESS = true;
			else if (start == 'e')
				IN_PROGRESS = false;
			else
				cout << "Wrong input! Try again.\n\n";
		} while (IN_PROGRESS != true && IN_PROGRESS != false);

		while (IN_PROGRESS)
		{
			cout << "---------Game start!---------\n\n";

			Deck deck;

			deck.shuffleDeck();

			cout << "Enter your name: ";
			string name;
			cin.ignore();
			getline(cin, name);
			cout << "\n";

			Player human(name);
			Player dealer;

			distribute(human, dealer, deck);

			human.printHand();
			dealer.printHand();

			cout << "Press enter to continue.";
			cin.ignore();
			turn(human, dealer, deck);
			dealer.printHand();
			checkWin(human, dealer);

			char choice;
			do {
				cout << "Would you like to play again? (y/n)";
				cin >> choice;
				choice = tolower(choice);

				if (choice == 'y')
					IN_PROGRESS = true;
				else if (choice == 'n')
					IN_PROGRESS = false;
				else
					cout << "Wrong input! Try again.\n\n";
			} while (choice != 'y' && choice != 'n');
		}

		cout << "Thank you! Come again soon! :)";
	}
};

//==========================

int main()
{
	cout << "===============EX.1===============\n\n";

	Student studentA;
	Student studentB;
	Student studentC;
	
	studentA.setName();
	studentA.setAge();
	studentA.setWeight();
	studentA.setSex();
	studentA.setYears();

	studentB.setName();
	studentB.setAge();
	studentB.setWeight();
	studentB.setSex();
	studentB.setYears();

	studentC.setName();
	studentC.setAge();
	studentC.setWeight();
	studentC.setSex();
	studentC.setYears();

	studentA.print();
	studentB.print();
	studentC.print();

	cout << "===============EX.2===============\n\n";

	Apple a("red");
	Banana b;
	GrannySmith c;

	a.print();
	b.print();
	c.print();

	cout << "===============EX.3===============\n\n";

	Game g;
	g.start();
}
