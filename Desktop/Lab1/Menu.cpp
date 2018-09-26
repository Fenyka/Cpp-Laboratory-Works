/* Реализация меню программы */
#include <iostream>
#include <string>
#include <set>
#include "MatrixTask.h"

using namespace std;

// Преобразование строки к целому числу
int ValidSToI(const string& S)
{
	try {
		int res = stoi(S);
		return res;
	}
	catch (exception) {
		return INT32_MIN;
	}
}

// Печать главного меню
void PrintMainMenu()
{
	system("cls");
	cout << "\tРабота с матрицами\n" <<
		"1. Выбор способа ввода\n" <<
		"2. Выбор способа вывода\n" <<
		"3. Выполнение программы\n" <<
		"0. Выход\n" << endl;
}

// Печать меню выбора способа ввода/вывода
void PrintSubMenu(const string WayName)
{
	system("cls");
	cout << "\tВыбор способа " << WayName << "a\n" <<
		"1. Файл\n" <<
		"2. Консоль\n" <<
		"0. Вернуться в главное меню\n" << endl;
}

// Перегрузка вывода для IOWAY
ostream& operator <<(ostream& out, const IOWAY& item)
{
	return out << ((item == File) ? "Файл" : "Консоль");
}

// Получение символа между left и right
int GetValidItem(const int left, const int right)
{
	string line;
	int res;
	do {
		cout << "№ пункта: ";
		getline(cin, line);
		res = ValidSToI(line);
	} while (res < left || res > right);
	return res;
}

// Функция изменения способа ввода/вывода
void WayChange(IOWAY& item, const string WayName)
{
	PrintSubMenu(WayName);
	cout << "Текущий способ: " << item << endl;
	switch (GetValidItem(0, 2)) {
	case 1:
		item = File;
		break;
	case 2:
		item = Console;
		break;
	}
	return;
}

// Запуск главного меню
void RunMenu()
{
	IOWAY Input = File,
		  Output = File;
	while (true) {
		PrintMainMenu();
		cout << "Текущие параметры: ввод - " << Input << ", вывод - " << Output << endl;
		switch (GetValidItem(0, 3)) {
		case 1:
			WayChange(Input, "ввод");
			break;
		case 2:
			WayChange(Output, "вывод");
			break;
		case 3:
			TaskRun(Input, Output);
			break;
		case 0:
			return;
		}
	}
}