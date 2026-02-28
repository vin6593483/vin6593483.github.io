#include <iostream>
using namespace std;
int main(void) {
    int sales[8];
    for (int i = 0; i < 8; i++) {
        cin >> sales[i];
    }
    int total1 = 0;
    for (int i = 0; i < 4; i++) {
        total1 =total1+sales[i];
    }
    int total2 = 0;
    for (int i = 4; i < 8; i++) {
        total2 = total2 + sales[i];
    }
    cout << "salesman1:" << sales[0] << "," << sales[1] << "," << sales[2] << "," << sales[3] << "\n";
    cout << "total:" << total1 << "\n";
    cout << "salesman2:" << sales[4] << "," << sales[5] << "," << sales[6] << "," << sales[7] << "\n";
    cout << "total:" << total2 << "\n";
    cout << "sum:" << total1 + total2 << "\n";
    return 0;
}
