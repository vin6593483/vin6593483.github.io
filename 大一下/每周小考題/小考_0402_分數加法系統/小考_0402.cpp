#include<iostream>
using namespace std;
class fraction {
private:
	int up;
	int down;
	int integer;
public:
	fraction() {
		//等等往下就知道空建構元的意義
	}
	fraction(int a, int b) {
		up = a;
		down = b;
		integer = 0;
		if (up >= down) {
			integer++;
			up = up - down;
		}
	}
	fraction operator+(fraction f2) {
		fraction f;                                           //因為第九行有空建構元，所以才可以直接建立(凸顯空建構元的重要性)
		f.up = up + f2.up;
		f.down = down;
		f.integer = integer + f2.integer;
		if (f.up >= f.down) {
			f.integer++;
			f.up = f.up - f.down;
		}
		return f;
	}
	void show() {
		if (integer == 0) {
			cout << up << "/" << down << endl;
		}
		else if (up == 0) {
			cout << integer << endl;
		}
		else {
			cout << integer << " " << up << "/" << down << endl;
		}
	}
};
int main() {
	int Numerator_1, Numerator_2, Denominator;
	cin >> Numerator_1 >> Numerator_2 >> Denominator;
	fraction f1(Numerator_1, Denominator);
	fraction f2(Numerator_2, Denominator);
	fraction f3 = f1 + f2;
	f3.show();
	return 0;
}