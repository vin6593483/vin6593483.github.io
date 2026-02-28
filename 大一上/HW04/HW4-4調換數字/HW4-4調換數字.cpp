#include<iostream>
using namespace std;
int main(void) {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int a, b;
	cin >> a >> b;
	int goal1 = -1;
	int goal2 = -1;
	int i;
	for (i = 0; i < 10; i++) {
		if (arr[i] == a) {
			goal1 = i;
		}
		if (arr[i] == b) {
			goal2 = i;
		}
	}
	if (goal1 != -1 && goal2 != -1) {
		int timmybigcock = arr[goal1];
		arr[goal1] = arr[goal2];
		arr[goal2] = timmybigcock;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i];
		if (i < 9) {
			cout << "|";
		}
	}
	cout << "|" << "\n";
	return 0;
}
