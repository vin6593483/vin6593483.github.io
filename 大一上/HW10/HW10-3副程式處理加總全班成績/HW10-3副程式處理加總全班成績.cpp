#include<iostream>
using namespace std;
int pass(int n, int* ptr) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (*(ptr + i) >= 60) {
			count++;
		}
	}
	return count;
}
int main(void) {
	int n;
	int* ptr;
	cin >> n;
	ptr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> *(ptr + i);
	}
	cout << pass(n, ptr) << endl;
	free(ptr);
	return 0;
}
