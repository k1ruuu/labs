#include <iostream>
using namespace std;

bool Prime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
		return true;
	}
}
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	setlocale(LC_ALL, "rus");
	const int I = 100;
	const int J = 100;
	int mat[I][J];
	int sum[I] = { 0 };
	int i;
	int j;
	cout << "¬ведите кол-во строк: ";
	cin >> i;
	cout << "¬ведите кол-во столбцов: ";
	cin >> j;
	for (int h = 0; h < i; h++) {
		for (int g = 0; g < j; g++) {
			cin >> mat[h][g];
		}
	}
	int count = 0;
	for (int h = 0; h < i; h++) {
		for (int g = 0; g < j - 1; g++) {
			for (int l = 0; l < j - 1; l++) {
				if (mat[h][g] == mat[h][g + l]) {
					count++;
				}
			}
		}
	}
	if (count == j * i) {
		for (int h = 0; h < i; h++) {
			for (int g = 0; g < j; g++) {
				if (Prime(abs(mat[h][g]))) {
					for (int v = 0; v < i - 4; v++) {
						for (int b = 0; b < j - 3; b++) {
							for (int l = 0; l < i - 1; l++) {
								if (sum[v] > sum[v + l]) {
									swap(mat[v][b], mat[v + l][b]);
								}
							}
						}
					}
				}
			}
		}
	}
	for (int h = 0; h < i; h++) {
		for (int g = 0; g < j; g++) {
			sum[h] = sum[h] + abs(mat[h][g]);
		}
	}
	
	for (int h = 0; h < i; h++) {
		for (int g = 0;g < j; g++) {
			cout << mat[h][g] << ' ';
		}
		cout << endl;
	}
}