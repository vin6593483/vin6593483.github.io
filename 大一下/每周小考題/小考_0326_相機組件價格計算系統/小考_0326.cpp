#include<iostream>
#include<string>
using namespace std;
struct Item {
	string brand;
	int cost;
};
class Lens {
private:
	Item m[3] = { {"Sony",300},{"Nikon",400},{"Canon",500} };
	int out;
public:
	int find_price(string);
};
class Tripod {
private:
	Item c[3] = { {"Manfrotto",100},{"Joby",200},{"Recsur",300} };
	int out;
public:
	int find_price(string);
};
int Lens::find_price(string a) {
	for (int i = 0; i < 4; i++) {
		if (a == m[i].brand) {
			return m[i].cost;
		}
	}
	return 0;
}
int Tripod::find_price(string b) {
	for (int i = 0; i < 4; i++) {
		if (b == c[i].brand) {
			return c[i].cost;
		}
	}
	return 0;
}
class mycamera :public Lens, public Tripod {
private:
	int cost;
public:
	mycamera(string a, string b) {
		cost = Lens::find_price(a) + Tripod::find_price(b);
	}
	void show() {
		cout << "Cost:" << cost;
	}
};
int main() {
	string a, b;
	cin >> a >> b;
	mycamera c1(a, b);
	c1.show();
	return 0;
}