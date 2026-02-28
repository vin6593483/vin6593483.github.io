#include<iostream>
using namespace std;
void MAX(int n, float* ptr) {
	float max = *(ptr);
	for (int i = 1; i < n; i++) {
		if (*(ptr + i) > max) {
			max = *(ptr + i);
		}
	}
	cout << max << " ";
}
void ALL(int n, float* ptr) {
	float all = 0;
	for (int i = 0; i < n; i++) {
		all = all + *(ptr + i);
	}
	float pingjun = all / n;
	cout << pingjun;
}
int main(void) {
	int n;
	cin >> n;
	float* ptr;
	ptr = (float*)malloc(n * sizeof(float));
	for (int i = 0; i < n; i++) {
		cin >> *(ptr + i);
	}
	MAX(n, ptr);
	ALL(n, ptr);
	free(ptr);
	return 0;
}
