#include <iostream>
using namespace std;

int main()
{
	char str[100] = "iuewrbhgpierwufgsiyegfTRYOUAggfysea";
	char vol[7] = "aeioyu";
	for (int i = 0; i < strlen(str); i++) {
		for (int j = 0;j < strlen(vol);j++)
			if (str[i] == vol[j]) {
				str[i] -= 32;
			}
	}
	cout << str;
}