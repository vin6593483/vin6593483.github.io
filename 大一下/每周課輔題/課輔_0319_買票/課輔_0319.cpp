#include <iostream>
using namespace std;
class ticket {
protected:
	char type;
	char isMember;
};
class order :protected ticket {
public:
	int price;
	order(char a, char b) {
		type = a;
		isMember = b;
		if (b == 'Y' || b == 'y') {
			if (a == 'a' || a == 'A') {
				price = 240;
			}
			else {
				price = 180;
			}
		}
		else {
			if (a == 'a' || a == 'A') {
				price = 300;
			}
			else {
				price = 200;
			}
		}
	}
	void display() {
		cout << "票種:" << type << endl;
		cout << "會員狀態:" << isMember << endl;
		cout << "最終金額:" << price << "元" << endl;
	}
};
int main() {
	char a;
	char b;
	cin >> a >> b;
	order p1(a, b);
	p1.display();
	return 0;
}