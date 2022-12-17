#include <iostream>
#include "Func.hpp"
using namespace std;
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
	if (flag1(g, h, mas) && flag2(h, g, mas)) {
		SumOfStrings(h, g, mas, sum);
		StringSort(h, g, mas, sum);
	}
	outPut_mas(h, g, mas);
	system("pause");
}