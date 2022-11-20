#include "Func.hpp"
#include <iostream>

namespace mt {
	bool isPrime(int x) {
		if (x < 2) {
			return false;
		}
		for (int i = 2; i < x; i++) {
			if (x % i == 0) {
				return false;
			}
			return true;
		}
	}
	bool isEqual(int x[100], int y[100], int n) {
		for (int i = 0; i < n; i++) {
			if (x[i] != y[i]) {
				return false;
			}
		}
		return true;
	}
	bool flag1(int g, int h, int mas[100][100]) {
		for (int i = 0; i < g - 1; i++) {
			int x[100];
			int y[100];
			for (int j = i + 1; j < g; j++) {
				for (int k = 0; k < h; k++) {
					x[k] = mas[k][i];
					y[k] = mas[k][j];
				}
				if (isEqual(x, y, h)) {
					return true;
					break;
				}
			}
		}
	}
	bool flag2(int h, int g, int mas[100][100]) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < g; j++) {
				if (isPrime(abs(mas[i][j]))) {
					return true;
					break;
				}
			}
		}
	}
	void outPut_mas(int h, int g, int mas[100][100]) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < g; j++) {
				std::cout << mas[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
	void inPut_mas(int h, int g, int mas[100][100]) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < g; j++) {
				std::cin >> mas[i][j];
			}
		}
	}
	int SumOfStrings(int h, int g, int mas[100][100], int sum[100]) {
		if (flag1(g, h, mas) && flag2(h, g, mas)) {
			for (int k = 0; k < h; k++) {
				for (int i = 0; i < g; i++) {
					sum[k] += abs(mas[k][i]);
				}
			}
		}
	}
	void StringSort(int h, int g, int mas[100][100], int sum[100]) {
		for (int i = 0; i < h - 1; i++) {
			for (int k = i; k < h; k++) {
				int tmp;
				if (sum[i] > sum[k]) {

					for (int j = 0; j < g; j++) {

						tmp = mas[i][j];
						mas[i][j] = mas[k][j];
						mas[k][j] = tmp;
					}

					tmp = sum[i];
					sum[i] = sum[k];
					sum[k] = tmp;
				}
			}
		}
	}
}