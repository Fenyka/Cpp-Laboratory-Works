// ������������ ���� ��� ������ Point
#pragma once
using namespace std;

class Point
{
public:
	double x, y;
	// ~ ����� Init(), ���������� ��� ����������� ������
	Point(){ x = 0; y = 0; }
	Point(const double& _x, const double& _y)
	{
		x = _x;
		y = _y;
	}

	// ���� ������ � ����������
	void Read();

	// ����� ������ �� �����
	void Display();

	// �������������� � ������
	string ToString();

	// �������� �����
	void MoveX(const double& px);
	void MoveY(const double &py);

	// ���������� �� ������ ���������
	double DistanceToZero();

	// ���������� ����� ����� �������
	static double Dist(const Point& P1, const Point& P2);

	// �������������� � �������� ���������� (���� R, Alpha)
	pair <double, double> ToPolar();

	// ��������� �� ����������
	static bool Equal(const Point& P1, const Point& P2);
};

// ���������� �����
istream& operator >> (istream& in, Point& P);

// ���������� ������
ostream& operator << (ostream& out, const Point& P);

// ���������� ���������� ��������� ==, !=
bool operator == (const Point& P1, const Point& P2);
bool operator != (const Point& P1, const Point& P2);