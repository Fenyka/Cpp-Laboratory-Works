// Заголовочный файл для класса Point
#pragma once
using namespace std;

class Point
{
public:
	double x, y;
	// ~ Метод Init(), реализован как конструктор класса
	Point(){ x = 0; y = 0; }
	Point(const double& _x, const double& _y)
	{
		x = _x;
		y = _y;
	}

	// Ввод данных с клавиатуры
	void Read();

	// Вывод данных на экран
	void Display();

	// Преобразование к строке
	string ToString();

	// Движение точки
	void MoveX(const double& px);
	void MoveY(const double &py);

	// Расстояние до начала координат
	double DistanceToZero();

	// Расстояние между двумя точками
	static double Dist(const Point& P1, const Point& P2);

	// Преобразование в полярные координаты (пара R, Alpha)
	pair <double, double> ToPolar();

	// Сравнение на совпадение
	static bool Equal(const Point& P1, const Point& P2);
};

// Перегрузка ввода
istream& operator >> (istream& in, Point& P);

// Перегрузка вывода
ostream& operator << (ostream& out, const Point& P);

// Перегрузка операторов сравнения ==, !=
bool operator == (const Point& P1, const Point& P2);
bool operator != (const Point& P1, const Point& P2);
