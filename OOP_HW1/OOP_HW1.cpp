#include <iostream>
#include <cstdint>

using namespace std;

//============EX.1============

//Создать класс Power, который содержит два вещественных числа.Этот класс должен иметь две переменные - члена для хранения этих вещественных чисел.
//Еще создать два метода : один с именем set, который позволит присваивать значения переменным, второй — calculate, 
//который будет выводить результат возведения первого числа в степень второго числа.Задать значения этих двух чисел по умолчанию.

class Power
{
	double m_base = 2.5;
	double m_power = 2;

public:
	Power()
	{}

	void set(double base, double power)
	{
		m_base = base;
		m_power = power;
	}

	void calculate()
	{
		double answer = m_base;
		for (int i = 1; i < m_power; i++)
			answer *= m_base;
		cout << "The answer is: " << answer << endl;
	}
};

//============================

//============EX.2============

//Написать класс с именем RGBA, который содержит 4 переменные - члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha(#include cstdint для доступа к этому типу).
//Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.Создать конструктор со списком инициализации членов, 
//который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.Написать функцию print(), которая будет выводить значения переменных - членов.

class RGBA
{
	uint8_t m_red = 0;
	uint8_t m_green = 0;
	uint8_t m_blue = 0;
	uint8_t m_alpha = 255;

public:

	RGBA()
	{}

	RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
		: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{}

	void print()
	{
		cout << "Red: " << int(m_red) << "\nGreen: " << int(m_green) << "\nBlue: " << int(m_blue) << "\nAlpha: " << int(m_alpha) << "\n\n";
	}
};

//============================

//============EX.3============

//Написать класс, который реализует функциональность стека.Класс Stack должен иметь :
//private - массив целых чисел длиной 10;
//private целочисленное значение для отслеживания длины стека;
//public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
//public - метод с именем push(), который будет добавлять значение в стек.push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
//public - метод с именем pop() для вытягивания и возврата значения из стека.Если в стеке нет значений, то должно выводиться предупреждение;
//public - метод с именем print(), который будет выводить все значения стека.

const int SZ = 10;

class Stack
{
	int arr[SZ] = { 0 };
	int length = 0;

public:

	Stack()
	{}

	void reset()
	{
		for (int i = 0; i < SZ; i++)
			arr[i] = 0;

		length = 0;
	}

	bool push(int value)
	{
		if (length == SZ)
		{
			cout << "Stack overflow!\n\n";
			return false;
		}

		for (int i = 0; i < SZ; i++)
		{
			if (arr[i] == 0)
			{
				arr[i] = value;
				length++;
				return true;
			}
		}
	}

	int pop()
	{
		if (length == 0)
		{
			cout << "Stack is empty!\n\n";
			return 1;
		}

		int tmp = arr[length - 1];
		arr[length - 1] = 0;
		length--;
		return tmp;
	}

	void print()
	{
		cout << "( ";

		for (int i = 0; i < length; i++)
			cout << arr[i] << " ";
		
		cout << ")\n\n";
	}
};

//============================

int main()
{
	cout << "================EX.1================\n\n";

	Power pwr;

	pwr.calculate();

	pwr.set(2, 4);
	pwr.calculate();

	pwr.set(2, 3);
	pwr.calculate();

	pwr.set(3, 3);
	pwr.calculate();

	cout << "\n================EX.2================\n\n";

	RGBA colors;
	colors.print();

	RGBA setColors(255, 255, 255, 0);
	setColors.print();

	cout << "================EX.3================\n\n";

	Stack stack;

	stack.reset();
	stack.pop();
	stack.print();

	stack.push(4);
	stack.push(1);
	stack.push(9);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	for (int i = 1; i < 12; i++)
		stack.push(i);
}
