#include<iostream>
using namespace std;
struct Part {
	string Model;
	int cost;
};
class CPU {
private:
	Part p[3] = { {"i5",100},{"i7",200},{"i9",300} };
	int out;
public:
	int find_price(string);
};
class GPU {
private:
	Part g[3] = { {"4060",200},{"4070",400},{"4080",600} };
	int out;
public:
	int find_price(string);
};
int CPU::find_price(string a) {
	for (int i = 0; i < 3; i++) {
		if (a == p[i].Model) {
			return p[i].cost;
		}
	}
	return 0;
}
int GPU::find_price(string b) {
	for (int i = 0; i < 3; i++) {
		if (b == g[i].Model) {
			return g[i].cost;
		}
	}
	return 0;
}
class myPC :public CPU, public GPU {
private:
	int cost;
public:
	myPC(string a, string b) {
		cost = CPU::find_price(a) + GPU::find_price(b);
	}
	void show() {
		cout << "Total Cost:" << cost;
	}
};
int main() {
	string cpu_name, gpu_name;
	cin >> cpu_name >> gpu_name;
	myPC pc1(cpu_name, gpu_name);
	pc1.show();
	return 0;
}