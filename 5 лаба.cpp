#include <iostream>
#include <fstream>
#include <string>
//#include <Windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	char b;
	cin >> b;
	int N;
	cin >> N;
	int max = INT_MIN;
	int sizee[100] = { INT_MIN };
	string s[100];
	int k = 0;
	string str;
	ifstream in("text.txt", ios::in);
	ofstream out("output.txt", ios::out);
	while (in >> str) {
		while (ispunct(str[0])) {
			str.erase(0,1);
			if (str.length() == 0) break;
		}
		if (str.length() == 0) continue;
		while (ispunct(str[str.length()-1])) {
			str.erase(str.length() - 1);
			if (str.length() == 0) break;
		}
		if (str.length() == 0) continue;
		for (int i = 0; i < str.length(); i++) {
			if (toupper(str[i])) {
				str[i] = tolower(str[i]);
			}
		}
		if (str[str.length() - 1] == b) {
			bool flag = true;
			for (int i = 0; i < k; i++) {
				if (str == s[i]) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				s[k] = str;
				k++;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - i - 1; j++){
			if (s[j].size() < s[j + 1].size()) {
				string tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		out << s[i] << '\n';
	}
	system("pause");

}