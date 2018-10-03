/* ������� ����� Point ��� ������ � ������� �� ���������.���������� ����� ���������.
����������� ������ ���� ����������� : ����������� ����� �� ��� X, ����������� ����� Y, 
����������� ���������� �� ������ ���������, ���������� ����� ����� �������,
�������������� � �������� ����������, ��������� �� ���������� � ������������. 
	������� �. */
#include <iostream>
#include <fstream>
#include <string>
#include "Point.h"

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void NullConstructorTest()
{
	out << "� ���� �������� �����������: " << Point() << endl;
}

void ParametersConstructorTest()
{
	Point a;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	out << "� ���� ������������ �� ����������: " << a << endl;
}

void ToStringTest()
{
	Point a;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	out << "� ���� ������ ToString: " << a.ToString() << endl;
}

void DistanseToZeroTest()
{
	Point a;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	out << "� ���� ������ DistanceToZero: " << a.DistanceToZero() << endl;
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
	out << "� ���� ������� MoveX, MoveY:" << endl << a << ":" << endl;
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
	out << "� ���� ������ Dist: " << Point::Dist(a, b) << endl;
}

void ToPolarTest()
{
	Point a;
	double x, y;
	in.ignore(256, ':');
	in >> x >> y;
	a = Point(x, y);
	auto Pa = a.ToPolar();
	out << "� ���� ������ ToPolar: R = " << Pa.first << ", alpha = " << Pa.second << endl;
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
	out << "� ���� ������ Equal: " << Point::Equal(a, b) << endl;
}

void ReadDisplayTest()
{
	Point a;
	cout << "���� ������ Read - ������� 2 �����:" << endl;
	a.Read();
	cout << "���� ������ Display: "; 
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
	cout << "�����, �� ��������� ������������� �������, ���������. ���������� � ����� output.txt" << endl;
	ReadDisplayTest();

	system("pause");
	return 0;
}