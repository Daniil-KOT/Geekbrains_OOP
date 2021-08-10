#include <iostream>
#include <exception>

using namespace std;

//================EX.1================
//Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров 
//и запускать исключение DivisionByZero, если второй параметр равен 0. 
//В функции main выводить результат вызова функции div в консоль, а также ловить исключения.

exception DivisionByZero()
{
	exception div_exception("Denominator cannot be equal to zero!\n");
	return div_exception;
}

template<typename T>
T Div(T numerator, T denominator)
{
	if (denominator == 0)
	{
		throw DivisionByZero();
	}
	else
	{
		T result = numerator / denominator;
		return result;
	}
}

//====================================

//================EX.2================
//Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, 
//инициализирующий x значением параметра. Написать класс Bar, хранящий вещественное число y(конструктор по умолчанию инициализирует его нулем) 
//и имеющий метод set с единственным вещественным параметром a.Если y + a > 100, возбуждается исключение типа Ex с данными a* y, 
//иначе в y заносится значение a.В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
//Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
//В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.

class Ex
{
public:

	double x_;

	Ex(const double& x) 
		: x_(x)
	{}
};

class Bar
{
	double y_;

public:

	Bar(double y = 0.0)
		: y_(y)
	{}

	void Set(double a)
	{
		if (y_ + a > 100)
		{
			throw Ex(a*y_);
		}
		else
		{
			y_ = a;
		}
	}
};

//====================================

//================EX.3================
//Написать класс «робот», моделирующий перемещения робота по сетке 10x10, 
//у которого есть метод, означающий задание переместиться на соседнюю позицию.
//Эти методы должны запускать классы - исключения OffTheField, если робот должен уйти с сетки, 
//и IllegalCommand, если подана неверная команда(направление не находится в нужном диапазоне).
//Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.
//Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов, 
//а также выводящую подробную информацию о всех возникающих ошибках.

const int SIZE = 10;

class OffTheField
{
	int x_current_;
	int y_current_;
	int x_desired_;
	int y_desired_;

public:

	OffTheField(int x_c, int y_c, int x_d, int y_d)
		:x_current_(x_c), y_current_(y_c), x_desired_(x_d), y_desired_(y_d)
	{}

	void what()
	{
		cerr << "Cannot move from coordinates (x) = " << x_current_ + 1 << ", (y) = " << y_current_ + 1
			<< "\nto the coordinates (x) = " << x_desired_ + 1 << ", (y) = " << y_desired_ + 1
			<< "!\nDesired coordinates are out of the map!\n";
	}
};

class IllegalCommand
{
	int x_current_;
	int y_current_;
	int x_desired_;
	int y_desired_;

public:

	IllegalCommand(int x_c, int y_c, int x_d, int y_d)
		:x_current_(x_c), y_current_(y_c), x_desired_(x_d), y_desired_(y_d)
	{}

	void what()
	{
		cerr << "Cannot move from coordinates (x) = " << x_current_ + 1 << ", (y) = " << y_current_ + 1
			<< "\nto the coordinates (x) = " << x_desired_ + 1 << ", (y) = " << y_desired_ + 1
			<< "!\nDesired coordinates are out of the reach!\n";
	}

};

class Robot
{
	int x_;
	int y_;
	char map_[SIZE][SIZE];
	enum Moves { CURRENT_POSITION = 'X', POSSIBLE_MOVE = '+', NO_MOVE = '-' };

public:

	Robot(int x = 0, int y = 0)
		:x_(x), y_(y)
	{}

	void CreateMap()
	{
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				map_[i][j] = NO_MOVE;

		map_[y_][x_] = CURRENT_POSITION;
		map_[y_ + 1][x_] = POSSIBLE_MOVE;
		map_[y_][x_ + 1] = POSSIBLE_MOVE;
		map_[y_ + 1][x_ + 1] = POSSIBLE_MOVE;

		if (x_ > 0)
		{
			map_[y_][x_ - 1] = POSSIBLE_MOVE;
			map_[y_ + 1][x_ - 1] = POSSIBLE_MOVE;
		}
		if (y_ > 0)
		{
			map_[y_ - 1][x_] = POSSIBLE_MOVE;
			map_[y_ - 1][x_ + 1] = POSSIBLE_MOVE;
		}
		if (y_ > 0 && x_ > 0)
		{
			map_[y_ - 1][x_ - 1] = POSSIBLE_MOVE;
		}
	}

	void PrintMap()
	{
		cout << " \t";
		for (int i = 0; i < SIZE; i++)
			cout << i + 1 << "  ";
		cout << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << "\n " << i + 1 << "\t";
			for (int j = 0; j < SIZE; j++)
			{
				cout << map_[i][j] << "  ";
			}
			cout << endl;
		}
		cout << "\n\n";
	}

	void Move(int x, int y)
	{
		if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
		{
			throw OffTheField(x_, y_, x, y);
		}
		else if (map_[y][x] == NO_MOVE)
		{
			throw IllegalCommand(x_, y_, x, y);
		}
		else
		{
			x_ = x;
			y_ = y;
			CreateMap();
			PrintMap();
		}
	}
};

//====================================


int main()
{
	cout << "================EX.1================\n\n";

	try
	{
		cout << Div<int>(5, 0) << endl;
	}
	catch(exception& exception)
	{
		cerr << "Exception: " << exception.what() << endl;
	}

	cout << "\n================EX.2================\n\n";

	Bar b;
	int n;
	
	do
	{	
		cout << "Enter an integer value: ";
		cin >> n;
		cout << endl;
		try
		{
			b.Set(n);
		}
		catch (Ex& exception)
		{
			cout << "Exception: " << exception.x_ << endl;
		}
	} while (n != 0);

	cout << "================EX.3================\n\n";

	Robot r(4, 4);
	r.CreateMap();
	r.PrintMap();
	try
	{
		r.Move(3, 6);
	}
	catch (OffTheField& otf)
	{
		otf.what();
	}
	catch (IllegalCommand& ic)
	{
		ic.what();
	}
}
