#include <iostream>
#include "Func.hpp"
using namespace std;
namespace mt {
	bool isPrime(int x);
	bool isEqual(int x[100], int y[100], int n);
	bool flag1(int g, int h, int mas[100][100]);
	bool flag2(int h, int g, int mas[100][100]);
	void outPut_mas(int h, int g, int mas[100][100]);
	void inPut_mas(int h, int g, int mas[100][100]);
	int SumOfStrings(int h, int g, int mas[100][100], int sum[100]);
	void StringSort(int h, int g, int mas[100][100], int sum[100]);
};
using namespace mt;



int main() {
	setlocale(LC_ALL, "rus");
	const int I = 100;
	const int J = 100;
	int h;
	int g;
	int mas[I][J];
	cout << "¬ведите кол-во строк: ";
	cin >> h;
	cout << "¬ведите кол-во столбцов: ";
	cin >> g;
	inPut_mas(h, g, mas);
	int sum[I] = { 0 };
	SumOfStrings(h, g, mas, sum);
	StringSort(h, g, mas, sum);
	outPut_mas(h, g, mas);
	system("pause");
}