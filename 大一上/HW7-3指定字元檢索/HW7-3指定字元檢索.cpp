#include<iostream>
using namespace std;
int main(void) {
	char a[20];
	char b;
	cin >> a >> b;
	int count = 0;
	for (int i = 0; i <= 19; i++) {
		if (a[i] == b) {
			count++;
		}
	}
	cout << count;
	return 0;
}