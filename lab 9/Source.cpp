#include <iostream>
using namespace std;

class Circle {
private:
	double m_Radius = 0;
public:
	Circle() {
		
	}
	~Circle(){}
	bool SetCircleRadius(double Radius) {
		if (Radius <= 0) {
			cout << "ќшибка в значении радиуса";
			return false;
		}
		else{
			m_Radius = Radius;
			return true;
		}
	}
	double AreaOfCircle() {
		double AOC = m_Radius * m_Radius * acos(-1);
		return AOC;
	}
};

int main() 
{
	setlocale(LC_ALL, "rus");
	Circle Circle1;
	int n;
	cout << "¬ведите радиус круга: ";
	cin >> n;
	if (Circle1.SetCircleRadius(n)) {
		cout << Circle1.AreaOfCircle();
	}
}