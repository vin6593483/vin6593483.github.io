#include<iostream>
#include<string>
using namespace std;
class zb {
private:
	int str;
	int agi;
	int integer;
public:
	zb() {
		str = agi = integer = 0;
	}
	zb operator+(zb a) {
		zb b;
		b.str = str + a.str;
		b.agi = agi + a.agi;
		b.integer = integer + a.integer;
		return b;
	}
	zb operator*(int a) {
		zb c;
		c.str = str * a;
		c.agi = agi * a;
		c.integer = integer * a;
		return c;
	}
	friend istream& operator>>(istream& in, zb &z) {
		in >> z.str >> z.agi >> z.integer;
		return in;
	}
	friend ostream& operator<<(ostream& out, zb &z) {
		out << "裝備結算: STR:" << z.str << " AGI:" << z.agi << " INT:" << z.integer << endl;
		return out;
	}
};
int main() {
	int choice = 0;
	cin >> choice;
	if (choice == 1) {
		zb z1, z2;
		cin >> z1 >> z2;
		zb z3 = z1 + z2;
		cout << z3;
	}
	else {
		zb z1;
		int x;
		cin >> z1;
		cin >> x;
		zb z4 = z1 * x;
		cout << z4;
	}
}