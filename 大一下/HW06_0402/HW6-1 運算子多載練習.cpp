#include<iostream>
#include<string>
using namespace std;
class circle {
private:
    float bj;
    string name;
    float area;
public:
    circle() {

    }
    circle(string a, float b) {
        name = a;
        bj = b;
        area = bj * bj * 3.14;
    }
    void show() {
        cout << "Circle " << name << ", Area=" << area << endl;
    }
    friend bool operator>(circle c1, circle c2);
    friend bool operator>(int n, circle c);
};
bool operator>(circle c1, circle c2) {
    return c1.area > c2.area;
}
bool operator>(int n, circle c) {
    return n > c.area;
}
int main(){
    string c11, c22;
    float c111, c222;
    cin >> c11 >> c111 >> c22 >> c222;
    circle c1(c11, c111), c2(c22, c222);
    if (c1 > c2){
        c1.show();
        cout << "bigger than" << endl;
        c2.show();
    }
    else{
        c1.show();
        cout << "smaller than" << endl;
        c2.show();
    }
    if (100 > c1){
        cout << "\n";
        c1.show();
        cout << "smaller than " << 100 << endl;
    }
    else{
        cout << "\n";
        c1.show();
        cout << "bigger than " << 100 << endl;
    }
    system("pause");
    return 0;
}
