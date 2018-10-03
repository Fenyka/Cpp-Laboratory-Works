// Файл реализации класса Point
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

// Ввод данных с клавиатуры
void Point::Read()
{
	cin >> x >> y;
}

// Вывод данных на экран
void Point::Display()
{
	cout << "(" << x << ", " << y << ")";
}

// Преобразование к строке
string Point::ToString()
{
	return "(" + to_string(x) + ", " + to_string(y) + ")";
}

// Движение точки
void Point::MoveX(const double& px)
{
	x += px;
}
void Point::MoveY(const double &py)
{
	y += py;
}

// Расстояние до начала координат
double Point::DistanceToZero()
{
	return sqrt(x * x + y * y);
}

// Расстояние между двумя точками
double Point::Dist(const Point& P1, const Point& P2)
{
	return hypot(P1.x - P2.x, P1.y - P2.y);
}

// Преобразование в полярные координаты (пара R, Alpha)
pair <double, double> Point::ToPolar()
{
	pair <double, double> res;
	res.first = (*this).DistanceToZero();
	res.second = atan2(y, x);
	return res;
}

// Сравнение на совпадение
bool Point::Equal(const Point& P1, const Point& P2)
{
	// Сравнение вещественных координат с точностью eps = 1e-7
	return (abs(P1.x - P2.x) <= 1e-7 && abs(P1.y - P2.y) <= 1e-7);
}

// Перегрузка ввода
istream& operator >> (istream& in, Point& P)
{
	return in >> P.x >> P.y;
}

// Перегрузка вывода
ostream& operator << (ostream& out, const Point& P)
{
	return out << "(" << P.x << ", " << P.y << ")";
}

// Перегрузка операторов сравнения ==, !=
bool operator == (const Point& P1, const Point& P2)
{
	return (abs(P1.x - P2.x) <= 1e-7 && abs(P1.y - P2.y) <= 1e-7);
}
bool operator != (const Point& P1, const Point& P2)
{
	return (abs(P1.x - P2.x) > 1e-7 || abs(P1.y - P2.y) > 1e-7);
}
