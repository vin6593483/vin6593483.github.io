#include<iostream>
using namespace std;
int add_num(int *a, int *b) {
	int c = 0;
	c = *a + *b;
	return c;
}
int main(void) {
	int a, b;
	cin >> a >> b;
	cout << add_num(&a, &b) << endl;
	return 0;
}