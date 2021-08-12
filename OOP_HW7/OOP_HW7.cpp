#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <memory>

#include "Game.h"

using namespace std;

//==============EX.1==============
//Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.Перегрузите оператор вывода для данного класса.
//Создайте два "умных" указателя today и date. Первому присвойте значение сегодняшней даты.
//Для него вызовите по отдельности методы доступа к полям класса Date, а также выведите на экран данные всего объекта 
//с помощью перегруженного оператора вывода.Затем переместите ресурс, которым владеет указатель today в указатель date.
//Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.

class Date
{
	int day_;
	int month_;
	int year_;

public:

	Date(int day, int month, int year)
		:day_(day), month_(month), year_(year)
	{}

	int GetDay() const
	{
		return day_;
	}

	int GetMonth() const
	{
		return month_;
	}

	int GetYear() const
	{
		return year_;
	}

	void SetDay(int day)
	{
		day_ = day;
	}

	void SetMonth(int month)
	{
		month_ = month;
	}

	void SetYear(int year)
	{
		year_ = year;
	}

	friend ostream& operator<<(ostream& out, Date& data);
};

ostream& operator<<(ostream& out, Date& data)
{
	out << "Day: " << data.day_ << "\nMonth: " << data.month_ << "\nYear: " << data.year_;
	return out;
}

//================================

//==============EX.2==============
//По условию предыдущей задачи создайте два умных указателя date1 и date2.
//Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой(сравнение происходит по датам).
//Функция должна вернуть более позднюю дату.
//Создайте функцию, которая обменивает ресурсами(датами) два умных указателя, переданных в функцию в качестве параметров.
//Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.

unique_ptr<Date>& CompareData(unique_ptr<Date>& data1, unique_ptr<Date>& data2)
{
	if (data1->GetYear() > data2->GetYear())
	{
		return data1;
	}
	else if(data1->GetMonth() > data2->GetMonth())
	{
		return data1;
	}
	else if (data1->GetDay() > data2->GetDay())
	{
		return data1;
	}
	else
	{
		return data2;
	}
}

void SwapData(unique_ptr<Date>& data1, unique_ptr<Date>& data2)
{
	data1.swap(data2);
}

//================================

int main()
{
	cout << "==============EX.1==============";

	auto today = make_unique<Date>(6, 8, 2021);
	unique_ptr<Date> date;

	today->SetDay(7);
	today->SetMonth(9);
	today->SetYear(2022);

	cout << *today << endl;

	cout << today << endl;
	cout << date << endl;

	today.swap(date);

	cout << *date << endl;
	date.reset();

	cout << today << endl;
	cout << date;

	cout << "\n\n==============EX.2==============\n\n";

	auto date1 = make_unique<Date>(7, 8, 2021);
	auto date2 = make_unique<Date>(9, 12, 2021);

	cout << "CompareData():\n\n";
	cout << *CompareData(date1, date2) << "\n\n";

	cout << "Before SwapData():\n\n";
	cout << *date1 << "\n\n";
	cout << *date2 << "\n\n";

	SwapData(date1, date2);

	cout << "After SwapData():\n\n";
	cout << *date1 << "\n\n";
	cout << *date2 << "\n\n";

	cout << "\n\n==============EX.5==============\n\n";
	//Написать функцию main() к игре Блекджек. В этой функции вводятся имена игроков.
	//Создается объект класса Game и запускается игровой процесс.
	//Предусмотреть возможность повторной игры.

	vector<string> player_names;

	char another_player;

	do
	{
		string name;

		cout << "Enter your name: ";
		getline(cin, name);

		player_names.push_back(name);

		cout << endl << "Would you like to add another player? (y/n)\n";
		another_player = tolower(foolProtection<char>());

	} while (another_player != 'n');

	Game start(player_names);

	start.Play();
}