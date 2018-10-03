/* Создать класс Point для работы с точками на плоскости.Координаты точки декартовы.
Обязательно должны быть реализованы : перемещение точки по оси X, перемещение пооси Y, 
определение расстояния до начала координат, расстояния между двумя точками,
преобразование в полярные координаты, сравнение на совпадение и несовпадение. 
	Андреев С. */
#include <iostream>
#include <fstream>
#include <string>
#include "Point.h"

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void NullConstructorTest()
{
	out << "• Тест простого контруктора: " << Point() << endl;
}

void ParametersConstructorTest()
{
	Point a;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	out << "• Тест конструктора по параметрам: " << a << endl;
}

void ToStringTest()
{
	Point a;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	out << "• Тест метода ToString: " << a.ToString() << endl;
}

void DistanseToZeroTest()
{
	Point a;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	out << "• Тест метода DistanceToZero: " << a.DistanceToZero() << endl;
}

void MoveTest()
{
	Point a, b;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	b = Point(x, y);
	in >> x >> y;
	out << "• Тест методов MoveX, MoveY:" << endl << a << ":" << endl;
	a.MoveX(x);
	b.MoveY(y);
	out << "MoveX for " << x << " = " << a << endl;
	out << "MoveY for " << y << " = " << b << endl;
}

void DistTest()
{
	Point a, b;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	in >> x >> y;
	b = Point(x, y);
	out << "• Тест метода Dist: " << Point::Dist(a, b) << endl;
}

void ToPolarTest()
{
	Point a;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	auto Pa = a.ToPolar();
	out << "• Тест метода ToPolar: R = " << Pa.first << ", alpha = " << Pa.second << endl;
}

void EqualTest()
{
	Point a, b;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	in >> x >> y;
	b = Point(x, y);
	out << "• Тест метода Equal: " << Point::Equal(a, b) << endl;
}

void ReadDisplayTest()
{
	Point a;
	cout << "Тест метода Read - введите 2 числа:" << endl;
	a.Read();
	cout << "Тест метода Display: "; 
	a.Display(); 
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	NullConstructorTest();
	ParametersConstructorTest();
	ToStringTest();
	DistanseToZeroTest();
	MoveTest();
	DistTest();
	ToPolarTest();
	EqualTest();
	cout << "Тесты, не требующие использования консоли, завершены. Результаты в файле output.txt" << endl;
	ReadDisplayTest();

	system("pause");
	return 0;
}
