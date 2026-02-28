#include<iostream>
using namespace std;
void change_num(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
int main(void) {
	int a, b;
	cin >> a >> b;
	change_num(&a, &b);
	cout << a << " " << b << endl;
	return 0;
}
