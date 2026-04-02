#include<iostream>
using namespace std;
class Length {
private:
	int m;
	int cm;
public:
	Length() {

	}
	Length(int a, int b) {
		m = a;
		cm = b;
	}
	Length operator+(Length n) {
		Length v;
		v.m = m + n.m;
		v.cm = cm + n.cm;
		if (v.cm >= 100) {
			v.m++;
			v.cm = v.cm - 100;
		}
		return v;
	}
	void show() {
		if (cm == 0) {
			cout << m << "M " << endl;
		}
		else {
			cout << m << "M " << cm << "cm" << endl;
		}
	}
};
int main() {
	int m1, cm1, m2, cm2;
	if (cin >> m1 >> cm1 >> m2 >> cm2) {
		Length L1(m1, cm1);
		Length L2(m2, cm2);
		Length L3 = L1 + L2;
		L3.show();
	}
	return 0;
}