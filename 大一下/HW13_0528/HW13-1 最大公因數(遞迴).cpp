#include<iostream>
using namespace std;
int get_hcf(int a, int b) {
	int i = 0;
	while (b != 0) {
		i = b;
		b = a % b;
		a = i;
	}
	return a;
}
int main(){
	int a, b;
	cin >> a >> b;
	cout << get_hcf(a, b);
	return 0;
}
