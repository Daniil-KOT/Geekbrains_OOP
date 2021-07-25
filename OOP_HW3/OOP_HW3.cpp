#include <iostream>
#include <string>

using namespace std;

//================EX.1================
//Создать абстрактный класс Figure(фигура).Его наследниками являются классы Parallelogram(параллелограмм) и Circle(круг).
//Класс Parallelogram — базовый для классов Rectangle(прямоугольник), Square(квадрат), Rhombus(ромб).
//Для всех классов создать конструкторы.Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

class Figure
{
public:
	virtual double area() = 0;
};

class Parallelogram : public Figure
{
	double a;
	double h;

public:

	Parallelogram()
	{
		cout << "Parallelogram::Parallelogram()\n\n";
	}

	void setValues()
	{
		cout << "Enter size of parallelogram's base: ";
		cin >> a;
		cout << "\nEnter size of parallelogram's height: ";
		cin >> h;
		cout << endl;
	}

	double area()
	{
		double S = a * h;
		return S;
	}
};

class Circle : public Figure
{
	double r;

public:

	Circle()
	{
		cout << "Circle::Circle()\n\n";
	}

	void setRadius()
	{
		cout << "Enter radius of the circle: ";
		cin >> r;
		cout << endl;
	}

	double area()
	{
		double S = pow(r, 2) * 3.14;
		return S;
	}
};

class Rectangle : public Parallelogram
{
	double a;
	double b;

public:

	Rectangle()
	{
		cout << "Rectangle::Rectangle()\n\n";
	}

	void setValues()
	{
		cout << "Enter the size of the first side of the rectangle: ";
		cin >> a;
		cout << "\nEnter the size of the second side of the rectangle: ";
		cin >> b;
		cout << endl;
	}

	double area()
	{
		double S = a * b;
		return S;
	}
};

class Square : public Parallelogram
{
	double a;

public:

	Square()
	{
		cout << "Square::Square()\n\n";
	}

	void setValue()
	{
		cout << "Enter the size of square side: ";
		cin >> a;
		cout << endl;
	}

	double area()
	{
		double S = a * a;
		return S;
	}
};

class Rhombus : public Parallelogram
{
	double a;
	double h;

public:

	Rhombus()
	{
		cout << "Rhombus::Rhombus()\n\n";
	}

	void setValues()
	{
		cout << "Enter size of the rhombus side: ";
		cin >> a;
		cout << "\nEnter size of the rhombus height: ";
		cin >> h;
		cout << endl;
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
	{
		Company = nameC;
		Model = nameM;
		cout << "Company:\t" << Company << "\n\nModel:\t\t" << Model << "\n\n";
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
	{
		Company = nameC;
		Model = nameM;
		cout << "Company:\t" << Company << "\n\nModel:\t\t" << Model << "\n\n";
	}
};

class Minivan : public PassengerCar, public Bus
{
public:

	Minivan(string nameC, string nameM)
	{
		Company = nameC;
		Model = nameM;
		cout << "Company:\t" << Company << "\n\nModel:\t\t" << Model << "\n\n";
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
		this->numerator = numerator;
		this->denominator = denominator;
	}

	void setValues()
	{
		cout << "Enter a numerator: ";
		cin >> numerator; 

		while (true)
		{
			cout << "Enter a denominator: ";
			cin >> denominator;

			if (denominator != 0)
				return;
			else
				cout << "Denominator cannot be equal to a zero! Try again.\n\n";
		}
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

public:

	void Flip()
	{
		if (Position)
			Position = false;
		else if (!Position)
			Position = true;
	}

	int getValue(Value& value)
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

	//Parallelogram pa;
	//Rectangle re;
	//Circle ci;
	//Square sq;
	//Rhombus rh;

	//pa.setValues();
	//re.setValues();
	//ci.setRadius();
	//sq.setValue();
	//rh.setValues();

	//cout << "Parallelogram area = " << pa.area() << "\n\nRectangle area = " << re.area() << "\n\nCircle area = " << ci.area() << "\n\nSquare area = " << sq.area() << "\n\nRhombus area = " << rh.area() << "\n\n";

	cout << "\n\n============EX.2============\n\n";

	//Car car("Audi", "80");
	//PassengerCar pCar("Audi", "R8");
	//Bus bus("Mercedes-Benz", "Sprinter");
	//Minivan minivan("Toyota", "Alphard");
	
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
