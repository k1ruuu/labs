#pragma once
namespace mt {
	bool isPrime(int x);
	bool isEqual(int x[100], int y[100], int n);
	bool flag1(int g, int h, int mas[100][100]);
	bool flag2(int h, int g, int mas[100][100]);
	void outPut_mas(int h, int g, int mas[100][100]);
	void inPut_mas(int h, int g, int mas[100][100]);
	int SumOfStrings(int h, int g, int mas[100][100], int sum[100]);
	void StringSort(int h, int g, int mas[100][100], int sum[100]);
}