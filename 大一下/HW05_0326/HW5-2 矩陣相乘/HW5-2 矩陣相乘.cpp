#include<iostream>
using namespace std;
class matrix {
private:
    int m[4];
public:
    void set(int a, int b, int c, int d) {
        m[0] = a;
        m[1] = b;
        m[2] = c;
        m[3] = d;
    }
    matrix operator*(matrix m2) {
        matrix m3;
        m3.m[0] = (m[0] * m2.m[0]) + (m[1] * m2.m[2]);
        m3.m[1] = (m[0] * m2.m[1]) + (m[1] * m2.m[3]);
        m3.m[2] = (m[2] * m2.m[0]) + (m[3] * m2.m[2]);
        m3.m[3] = (m[2] * m2.m[1]) + (m[3] * m2.m[3]);
        return m3;
    }
    void show() {
        cout << "matrix 3:" << endl;
        cout << m[0] << " " << m[1] << endl;
        cout << m[2] << " " << m[3] << endl;
    }
};
int main() {
    int n[8];
    matrix m1, m2, m3;
    for (int i = 0; i < 8; i++){
        cin >> n[i];
    }
    m1.set(n[0], n[1], n[2], n[3]);
    m2.set(n[4], n[5], n[6], n[7]);
    m3 = m1 * m2;
    m3.show();
    return 0;
}