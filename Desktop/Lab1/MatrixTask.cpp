#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

extern enum IOWAY { File, Console };

// ������� ������� ���� ��������
set<int> Merge(set<int> lhs, const set<int>& rhs)
{
	for (const auto& item : rhs)
		lhs.insert(item);
	return lhs;
}

// ������� ��������� ���������� �������� (�� �����/�������)
void GetRightSize(int& M, int& N, IOWAY Iway, ifstream& in)
{
	in >> M >> N;
	if (Iway == Console) {
		while (N < 1 || M < 1) {
			cout << "������� �������� ������, ����������, ��������� ����\n";
			in >> M >> N;
		}
	}
}

// ���������� ������� �� �����/�������
void GetMatrix(vector <vector<int>>& Matrix, int& M, int& N, ifstream& in)
{
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			in >> Matrix[j][i];
}

// ����� �������
void PrintMatrix(const vector <vector<int>>& Matrix, int& M, int& N, ofstream& out)
{
	if (N == 0)
		out << "������� �����" << endl;
	else
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) 
				out << Matrix[j][i] << " ";
			out << endl;
		}
}

// ����� �������� �������� � ����������� ���������
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

// ����� �������� �������� � ������������ ���������
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

// �������� �������� � ��������� �� ��������� Idx
void ColumnDelete(vector< vector<int>>& Matrix, const set<int>& Idx)
{
	// �������� ��������, ������� � �������� �������
	for (auto item = Idx.rbegin(); item != Idx.rend(); ++item)
		Matrix.erase(Matrix.begin() + *item);
}

// �������� ������ ������� �� ������������ ��-�� ��������������� �����
void AddFirstCol(vector< vector<int>>& Matrix, int& M, int& N)
{
	vector<int> FirstCol(M, 1);
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			FirstCol[i] *= Matrix[j][i];
	Matrix.emplace(Matrix.begin(), FirstCol);
	N++;
}

// ���������� �������
void TaskRun(IOWAY Input, IOWAY Output)
{
	int N, M;

	// ����������� ������� �����-������
	ifstream in("CON");
	ofstream out("CON");
	if (Input == File)
		in = ifstream("input.txt");
	if (Output == File)
		out = ofstream("output.txt");

	if (Input == Console)
		cout << "������� ������� ������� - 2 ����� M, N (������ 2)\n";
	GetRightSize(M, N, Input, in);
	
	vector <vector <int>> matrix(N, vector<int>(M));
	if (Input == Console)
		cout << "������� �������\n";
	GetMatrix(matrix, M, N, in);	

	set<int> Idx = Merge(GetMinIdx(matrix, M, N), GetMaxIdx(matrix, M, N));
	ColumnDelete(matrix, Idx);
	N -= Idx.size();

	if (N > 0)
		AddFirstCol(matrix, M, N);

	PrintMatrix(matrix, M, N, out);
	// �������� ��� �������
	if (Output == Console)
		system("pause");
	return;
}