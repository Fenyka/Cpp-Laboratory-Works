/* ���������� ���� ��������� */
#include <iostream>
#include <string>
#include <set>
#include "MatrixTask.h"

using namespace std;

// �������������� ������ � ������ �����
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

// ������ �������� ����
void PrintMainMenu()
{
	system("cls");
	cout << "\t������ � ���������\n" <<
		"1. ����� ������� �����\n" <<
		"2. ����� ������� ������\n" <<
		"3. ���������� ���������\n" <<
		"0. �����\n" << endl;
}

// ������ ���� ������ ������� �����/������
void PrintSubMenu(const string WayName)
{
	system("cls");
	cout << "\t����� ������� " << WayName << "a\n" <<
		"1. ����\n" <<
		"2. �������\n" <<
		"0. ��������� � ������� ����\n" << endl;
}

// ���������� ������ ��� IOWAY
ostream& operator <<(ostream& out, const IOWAY& item)
{
	return out << ((item == File) ? "����" : "�������");
}

// ��������� ������� ����� left � right
int GetValidItem(const int left, const int right)
{
	string line;
	int res;
	do {
		cout << "� ������: ";
		getline(cin, line);
		res = ValidSToI(line);
	} while (res < left || res > right);
	return res;
}

// ������� ��������� ������� �����/������
void WayChange(IOWAY& item, const string WayName)
{
	PrintSubMenu(WayName);
	cout << "������� ������: " << item << endl;
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

// ������ �������� ����
void RunMenu()
{
	IOWAY Input = File,
		  Output = File;
	while (true) {
		PrintMainMenu();
		cout << "������� ���������: ���� - " << Input << ", ����� - " << Output << endl;
		switch (GetValidItem(0, 3)) {
		case 1:
			WayChange(Input, "����");
			break;
		case 2:
			WayChange(Output, "�����");
			break;
		case 3:
			TaskRun(Input, Output);
			break;
		case 0:
			return;
		}
	}
}