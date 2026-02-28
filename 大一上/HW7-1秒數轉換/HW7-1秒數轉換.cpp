#include<iostream>
using namespace std;
int main(void) {
	int s;
	cin >> s;
	if (s >= 86400 || s<0) {
		cout << "error!\n";
		return 0;
	}
	int a, b, c;
	a = (s / 3600);
	b = (s % 3600) / 60;
	c = (s % 3600) % 60;
	cout << a << ":" << b << ":" << c;
	return 0;
}