#include<iostream>
using namespace std;
class product {
protected:
	char option;
	char add;
};
class buy :protected product {
public:
	int sum;
	buy(char x, char y, char z) {
		option = x;
		add = y;
		if (x == 'a' || x == 'A') {
			if (z == 'a' || z == 'A') {
				sum = 160;
			}
			else {
				sum = 135;
			}
		}
		else {
			if (z == 'a' || z == 'A') {
				sum = 120;
			}
			else {
				sum = 90;
			}
		}
	}
	buy(char x, char y) {
		option = x;
		add = y;
		if (x == 'a' || x == 'A') {
			sum = 100;
		}
		else {
			sum = 50;
		}
	}
	void show() {
		cout << "購買產品:" << option << endl;
		cout << "是否加購:" << add << endl;
		cout << "總金額:" << sum << endl;
	}
};
int main() {
	char p1, p2;
	char b;
	cin >> p1 >> p2;
	if (p2 == 'Y' || p2 == 'y') {
		cin >> b;
		buy b1(p1, p2, b);
		b1.show();
	}
	else if (p2 == 'N' || p2 == 'n') {
		buy b2(p1, p2);
		b2.show();
	}
	return 0;
}