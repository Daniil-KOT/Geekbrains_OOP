#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//================EX.1================
//Создать абстрактный класс Figure(фигура).Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
//Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
//Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

class Figure
{
public:
	Figure()
	{
		cout << "Figure::Figure()\n\n";
	}
	
	virtual double area() = 0;
};

class Parallelogram : public Figure
{
	double a = 0;
	double h = 0;

public:

	Parallelogram()
	{
		cout << "Parallelogram::Parallelogram()\n\n";
	}
	
	Parallelogram(double sa, double sh)
		:a(sa), h(sh)
	{

	}
	
	void setValues(double sa, double sh)
	{
		a = sa;
		h = sh;
	}

	double area()
	{
		double S = a * h;
		return S;
	}
};

class Circle : public Figure
{
	double r = 0;

public:

	Circle()
	{
		cout << "Circle::Circle()\n\n";
	}
	
	Circle(double sr)
		:r(sr)
	{

	}

	void setRadius(double sr)
	{
		r = sr;
	}

	double area()
	{
		double S = pow(r, 2) * 3.14;
		return S;
	}
};

class Rectangle : public Parallelogram
{
	double a = 0;
	double b = 0;

public:

	Rectangle()
	{
		cout << "Rectangle::Rectangle()\n\n";
	}
	
	Rectangle(double sa, double sb, double pa, double ph)
		:a(sa), b(sb), Parallelogram(pa, ph)
	{

	}

	void setValues(double sa, double sb)
	{
		a = sa;
		b = sb;
	}

	double area()
	{
		double S = a * b;
		return S;
	}
};

class Square : public Parallelogram
{
	double a = 0;

public:

	Square()
	{
		cout << "Square::Square()\n\n";
	}
	
	Square(double sa, double pa, double ph)
		:a(sa), Parallelogram(pa, ph)
	{

	}
	
	void setValue(double sa)
	{
		a = sa;
	}

	double area()
	{
		double S = a * a;
		return S;
	}
};

class Rhombus : public Parallelogram
{
	double a = 0;
	double h = 0;

public:

	Rhombus()
	{
		cout << "Rhombus::Rhombus()\n\n";
	}
	
	Rhombus(double sa, double sh, double pa, double ph)
		:a(sa), h(sh), Parallelogram(pa, ph)
	{

	}

	void setValues(double sa, double sh)
	{
		a = sa;
		h = sh;
	}

	double area()
	{
		double S = a * h;
		return S;
	}
};


//====================================

//================EX.2================
//Создать класс Car(автомобиль) с полями company(компания) и model(модель).Классы - наследники: PassengerCar(легковой автомобиль) и Bus(автобус).
//От этих классов наследует класс Minivan(минивэн).Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
//Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.Обратить внимание на проблему «алмаз смерти».

class Car
{
protected:

	string Company = "TBD";
	string Model = "TBD";

public:

	//Конструкторы такого типа делал для наглядности ("посмотреть, в какой последовательности выполняются конструкторы")
	Car()
	{
		cout << "Car::Car()\n\n";	
	}

	Car(string nameC, string nameM)
		: Company(nameC), Model(nameM)
	{
		cout << "Company:\t" << Company << "\n\nModel:\t\t" << Model << "\n\n";
	}

	void setCompany(string name)
	{
		Company = name;
	}

	void setModel(string name)
	{
		Model = name;
	}
};

class PassengerCar : public virtual Car
{
public:

	PassengerCar()
	{
		cout << "PassengerCar::PassengerCar()\n\n";
	}

	PassengerCar(string nameC, string nameM)
		:Car(nameC, nameM)
	{
		cout << "Company:\t" << this->Company << "\n\nModel:\t\t" << this->Model << "\n\n";
	}
};

class Bus : public virtual Car
{
public:

	Bus()
	{
		cout << "Bus::Bus()\n\n";
	}

	Bus(string nameC, string nameM)
		:Car(nameC, nameM)
	{
		cout << "Company:\t" << Bus::Company << "\n\nModel:\t\t" << Bus::Model << "\n\n";
	}
};

class Minivan : public PassengerCar, public Bus
{
public:

	Minivan(string nameC, string nameM)
		:Car(nameC, nameM)
	{
		cout << "Company:\t" << this->Company << "\n\nModel:\t\t" << this->Model << "\n\n";
	}
};

//====================================

//================EX.3================
//Создать класс : Fraction(дробь).Дробь имеет числитель и знаменатель(например, 3 / 7 или 9 / 2).Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить :
//	математические бинарные операторы(+, -, *, / ) для выполнения действий с дробями
//	унарный оператор(-)
//	логические операторы сравнения двух дробей(== , != , <, >, <= , >= ).

class Fraction
{
	int numerator;
	int denominator;

public:

	Fraction()
	{};

	Fraction(int numerator, int denominator)
	{
		assert(denominator != 0);
		this->numerator = numerator;
		this->denominator = denominator;
	}

	void setNumerator(int numerator)
	{
		this->numerator = numerator;
	}
	
	void setDenominator(int denominator)
	{
		if (denominator != 0)
			this->denominator = denominator;
		else
			cout << "Denominator cannot be equal to a zero! Try again.\n\n";
	}

	void Print()
	{
		cout << numerator << "/" << denominator << "\n\n";
	}

	Fraction operator+(Fraction& frac)
	{
		return Fraction(this->numerator * frac.denominator + this->denominator * frac.numerator, this->denominator * frac.denominator);
	}

	Fraction operator-(Fraction& frac)
	{
		return Fraction(this->numerator * frac.denominator - this->denominator * frac.numerator, this->denominator * frac.denominator);
	}

	Fraction operator*(Fraction& frac)
	{
		return Fraction(this->numerator * frac.numerator, this->denominator * frac.denominator);
	}
	
	Fraction operator/(Fraction& frac)
	{
		return Fraction(this->numerator * frac.denominator, this->denominator * frac.numerator);
	}

	Fraction operator-()
	{	
		return Fraction(-numerator, denominator);
	}

	bool operator==(Fraction& frac)
	{
		return (this->numerator == frac.numerator && this->denominator == frac.denominator);
	}

	bool operator>(Fraction& frac)
	{
		return (this->numerator > frac.numerator && this->denominator > frac.denominator);
	}

	friend bool operator<(Fraction& lh, Fraction& rh);

	friend bool operator!= (Fraction& lh, Fraction& rh);
};

bool operator<(Fraction& lh, Fraction& rh)
{
	return !(lh > rh);
}

bool operator!=(Fraction& lh, Fraction& rh)
{
		return !(lh == rh);
}

//====================================

//================EX.4================
//Создать класс Card, описывающий карту в игре БлэкДжек.У этого класса должно быть три поля : масть, значение карты и положение карты(вверх лицом или рубашкой).
//Сделать поля масть и значение карты типом перечисления(enum).Положение карты - тип bool.Также в этом классе должно быть два метода :
//метод Flip(), который переворачивает карту, т.е.если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
//метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.

class Card
{
	enum Suit { TAMBOURINE, SPADE, CLUBS, HEARTS};
	enum Value { ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN, SIX, FIVE, FOUR, THREE, TWO };
	bool Position = false;
	Value value;
	Suit suit;
	
public:

	void Flip()
	{
		if (Position)
			Position = false;
		else if (!Position)
			Position = true;
	}

	int getValue() const
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

//====================================


int main()
{
	cout << "============EX.1============\n\n";

	Parallelogram pa(3.3, 4);
	Rectangle re(4.2, 3.3, 2.2, 4.4);
	Circle ci(3.3);
	Square sq (4.1, 2.5, 7.3);
	Rhombus rh (7.1, 1.1, 2.2, 3.3);

	/*pa.setValues(2.5, 4);
	re.setValues(3.3, 2.1);
	ci.setRadius(4);
	sq.setValue(2.5);
	rh.setValues(6.2, 3.4);*/

	cout << "Parallelogram area = " << pa.area() << "\n\nRectangle area = " << re.area() << "\n\nCircle area = " << ci.area() << "\n\nSquare area = " << sq.area() << "\n\nRhombus area = " << rh.area() << "\n\n";

	cout << "\n\n============EX.2============\n\n";

	Car car("Audi", "80");
	PassengerCar pCar("Audi", "R8");
	Bus bus("Mercedes-Benz", "Sprinter");
	Minivan minivan("Toyota", "Alphard");
	
	cout << "\n\n============EX.3============\n\n";

	Fraction f1(3, 4);
	Fraction f2(4, 7);
	Fraction f3;

	f3 = f1 + f2;
	f3.Print();

	f3 = f1 - f2;
	f3.Print();

	f3 = f1 * f2;
	f3.Print();

	f3 = f1 / f2;
	f3.Print();

	if (f1 > f2)
		cout << "f1 > f2\n\n";
	else if (f1 < f2)
		cout << "f1 < f2\n\n";
	else
		cout << "It doesn't work\n\n";

	Fraction f4(3, 4);

	if (f4 == f1)
		cout << "f4 == f1\n\n";

	if (f4 != f2)
		cout << "f4 != f2\n\n";

	f2 = -f1;

	f2.Print();
}
