// ���� ���������� ������ Point
#include <iostream>
#include <string>
#include "Point.h"

using namespace std;

// ���� ������ � ����������
void Point::Read()
{
	cin >> x >> y;
}

// ����� ������ �� �����
void Point::Display()
{
	cout << "(" << x << ", " << y << ")";
}

// �������������� � ������
string Point::ToString()
{
	return "(" + to_string(x) + ", " + to_string(y) + ")";
}

// �������� �����
void Point::MoveX(const double& px)
{
	x += px;
}
void Point::MoveY(const double &py)
{
	y += py;
}

// ���������� �� ������ ���������
double Point::DistanceToZero()
{
	return sqrt(x * x + y * y);
}

// ���������� ����� ����� �������
double Point::Dist(const Point& P1, const Point& P2)
{
	return hypot(P1.x - P2.x, P1.y - P2.y);
}

// �������������� � �������� ���������� (���� R, Alpha)
pair <double, double> Point::ToPolar()
{
	pair <double, double> res;
	res.first = (*this).DistanceToZero();
	res.second = atan2(y, x);
	return res;
}

// ��������� �� ����������
bool Point::Equal(const Point& P1, const Point& P2)
{
	// ��������� ������������ ��������� � ��������� eps = 1e-7
	return (abs(P1.x - P2.x) <= 1e-7 && abs(P1.y - P2.y) <= 1e-7);
}

// ���������� �����
istream& operator >> (istream& in, Point& P)
{
	return in >> P.x >> P.y;
}

// ���������� ������
ostream& operator << (ostream& out, const Point& P)
{
	return out << "(" << P.x << ", " << P.y << ")";
}

// ���������� ���������� ��������� ==, !=
bool operator == (const Point& P1, const Point& P2)
{
	return (abs(P1.x - P2.x) <= 1e-7 && abs(P1.y - P2.y) <= 1e-7);
}
bool operator != (const Point& P1, const Point& P2)
{
	return (abs(P1.x - P2.x) > 1e-7 || abs(P1.y - P2.y) > 1e-7);
}