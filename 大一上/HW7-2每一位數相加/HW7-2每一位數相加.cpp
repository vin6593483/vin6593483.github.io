#include<iostream>
using namespace std;
int add_digits(int a) {
	int sum = 0;
	while (a != 0) {
		sum = sum + (a % 10);
		a = a / 10;
	}
	return sum;
}
int main(void) {
	int n;
	cin >> n;
	if (n < 1000000000) {
		cout << add_digits(n) << endl;
	}
	return 0;
}