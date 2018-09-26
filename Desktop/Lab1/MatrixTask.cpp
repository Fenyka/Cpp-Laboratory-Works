#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

extern enum IOWAY { File, Console };

// Функция слияния двух множеств
set<int> Merge(set<int> lhs, const set<int>& rhs)
{
	for (const auto& item : rhs)
		lhs.insert(item);
	return lhs;
}

// Функция получения корректных размеров (из файла/консоли)
void GetRightSize(int& M, int& N, IOWAY Iway, ifstream& in)
{
	in >> M >> N;
	if (Iway == Console) {
		while (N < 1 || M < 1) {
			cout << "Введены неверные данные, пожалуйста, повторите ввод\n";
			in >> M >> N;
		}
	}
}

// Считывание матрицы из файла/консоли
void GetMatrix(vector <vector<int>>& Matrix, int& M, int& N, ifstream& in)
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			in >> Matrix[j][i];
}

// Вывод матрицы
void PrintMatrix(const vector <vector<int>>& Matrix, int& M, int& N, ofstream& out)
{
	if (N == 0)
		out << "Матрица пуста" << endl;
	else
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) 
				out << Matrix[j][i] << " ";
			out << endl;
		}
}

// Поиск индексов столбцов с минимальным элементом
set<int> GetMinIdx(const vector< vector<int>>& Matrix, int& M, int& N)
{
	int min = INT_MAX;
	set<int> res;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (Matrix[i][j] < min) {
				res.clear();
				min = Matrix[i][j];
				res.insert(i);
			} else if (Matrix[i][j] == min) {
				res.insert(i);
			}
	return res;
}

// Поиск индексов столбцов с максимальным элементом
set<int> GetMaxIdx(const vector< vector<int>>& Matrix, int& M, int& N)
{
	int max = INT_MIN;
	set<int> res;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (Matrix[i][j] > max) {
				res.clear();
				max = Matrix[i][j];
				res.insert(i);
			}
			else if (Matrix[i][j] == max) {
				res.insert(i);
			}
	return res;
}

// Удаление столбцов с индексами из множества Idx
void ColumnDelete(vector< vector<int>>& Matrix, const set<int>& Idx)
{
	// Удаление столбцов, начиная с большего индекса
	for (auto item = Idx.rbegin(); item != Idx.rend(); ++item)
		Matrix.erase(Matrix.begin() + *item);
}

// Добпвить первый столбец из произведений эл-ов соответствующих строк
void AddFirstCol(vector< vector<int>>& Matrix, int& M, int& N)
{
	vector<int> FirstCol(M, 1);
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			FirstCol[i] *= Matrix[j][i];
	Matrix.emplace(Matrix.begin(), FirstCol);
	N++;
}

// Реализация задания
void TaskRun(IOWAY Input, IOWAY Output)
{
	int N, M;

	// Определение потоков ввода-вывода
	ifstream in("CON");
	ofstream out("CON");
	if (Input == File)
		in = ifstream("input.txt");
	if (Output == File)
		out = ofstream("output.txt");

	if (Input == Console)
		cout << "Введите размеры матрицы - 2 числа M, N (больше 2)\n";
	GetRightSize(M, N, Input, in);
	
	vector <vector <int>> matrix(N, vector<int>(M));
	if (Input == Console)
		cout << "Введите матрицу\n";
	GetMatrix(matrix, M, N, in);	

	set<int> Idx = Merge(GetMinIdx(matrix, M, N), GetMaxIdx(matrix, M, N));
	ColumnDelete(matrix, Idx);
	N -= Idx.size();

	if (N > 0)
		AddFirstCol(matrix, M, N);

	PrintMatrix(matrix, M, N, out);
	// Задержка для консоли
	if (Output == Console)
		system("pause");
	return;
}