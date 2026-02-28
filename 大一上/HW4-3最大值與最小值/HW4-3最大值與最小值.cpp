#include<iostream>
using namespace std;
int main(void) {
	int num[10];
	int i;
	for (i = 0; i < 10; i++) {
		cin >> num[i];
	}
	int max = num[0];
	int min = num[0];
	for (i = 1; i < 10; i++) {
		if (num[i] > max) {
			max = num[i];
		}
		if (num[i] < min) {
			min = num[i];
		}
	}
	cout << "max:" << max << "\n";
	cout << "min:" << min << "\n";
	return 0;
}