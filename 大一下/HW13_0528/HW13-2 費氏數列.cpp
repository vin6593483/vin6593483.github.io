#include<iostream>
using namespace std;
int f(int a) {
	if (a == 1) {
		return 0;
	}
	else if (a == 2) {
		return 1;
	}
	else if (a <= 0) {
		return 0;
	}
	else {
		return f(a - 1) + f(a - 2);
	}
}
int main(){
	int x;
	cin >> x;
	cout << f(x) << endl;    //題目是要我們輸出第N個費氏數列數，不是算費氏數列，所以沒有f(0)
	return 0;
}