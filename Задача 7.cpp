#include <iostream>
using namespace std;

int main() {
	int q1, q2, p1, p2, a;
	cin >> q1;
	cin >> p1;
	cin >> q2;
	cin >> p2;
	cin >> a;
	int min = INT_MAX;
	
	for (int i = 0; i < a/q1+1; i++) {
		for (int j = 0; j < a / q2 + 1; j++) {
			int sum = 0;
			if ((i * q1 + j * q2) >= a) {
				sum = i*p1 + j*p2;
				if (sum < min) {
					min = sum;
				}
			}
		}
	}
	cout << min;
	system("pause");
}