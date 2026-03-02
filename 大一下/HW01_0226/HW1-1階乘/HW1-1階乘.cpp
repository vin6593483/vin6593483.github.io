#include<iostream>
using namespace std;
int f(int n) {
	int sum = 1;
	cout << n;
	for (int i = n; i > 1; i--) {
		sum = sum * i;
		cout << "*" << i - 1;
	}
	return sum;
}
int main(void)
{
	int a;
	cin >> a;
	int b = f(a);
	cout << "=" << b << endl;
	return 0;
}