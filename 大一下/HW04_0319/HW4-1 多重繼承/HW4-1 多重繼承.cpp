#include<iostream>
#include<string>
using namespace std;
struct Item {
    string Brand;
    int price;
};
class Monitor {
private:
    Item m[3] = { {"Sony",100},{"ViewSonic",200},{"Samsung",300} };
    int out;
public:
    int find_price(string);
};
class CPU {
private:
    Item c[3] = { {"Core_i3",100},{"Core_i5",200},{"Core_i7",300} };
    int out;
public:
    int find_price(string);
};
class RAM {
private:
    Item r[3] = { {"Kingston",100},{"ADATA",200},{"Micron",300} };
    int out;
public:
    int find_price(string);
};
int Monitor::find_price(string a) {
    for (int i = 0; i < 3; i++) {
        if (m[i].Brand == a) {
            return m[i].price;
        }
    }
}
int CPU::find_price(string b) {
    for (int i = 0; i < 3; i++) {
        if (c[i].Brand == b) {
            return c[i].price;
        }
    }
}
int RAM::find_price(string c) {
    for (int i = 0; i < 3; i++) {
        if (r[i].Brand == c) {
            return r[i].price;
        }
    }
}
class mycomp :public Monitor, public CPU, public RAM {
private:
    int cost;
public:
    mycomp() {
        cost = 0;
    }
    mycomp(string a, string b, string c) {
        cost = Monitor::find_price(a) + CPU::find_price(b) + RAM::find_price(c);
    }
    void show() {
        cout << "Cost:" << cost << endl;
    }
};
int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    mycomp c1(a, b, c);
    c1.show();
    return 0;
}
