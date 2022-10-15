#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char b;
	cin >> b;
	int max = INT_MIN;
	int sizee[100] = { INT_MIN };
	string str;
	ifstream in("text.txt", ios::in);
	ofstream out("output.txt", ios::out);
	while (in >> str) {
		if (str[str.length() - 1] == b) {
			out << str << '\n';
		}
	}

}