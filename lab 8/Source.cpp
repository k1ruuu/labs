#include<iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    int byte;
    cout << "¬ведите число: ";
    cin >> n;

    char* pb;
    pb = (char*)&n;

    for (char* i = pb; i < pb + 4; i++)
    {
        byte = (int)*i;
        if (byte < 0) {
            cout << byte + 256 << " ";
        }
        else {
            cout << byte << " ";
        }
    }
}