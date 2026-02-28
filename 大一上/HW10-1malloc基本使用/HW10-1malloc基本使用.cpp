#include<iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	float* ptr;
	ptr = (float*)malloc(n * sizeof(float));
	for (int i = 0; i < n; i++) {
		cin >> *(ptr + i);
	}
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			*(ptr + i) = *(ptr + i) + 3;
		}
		else {
			*(ptr + i) = *(ptr + i) * 2;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << *(ptr + i) << " ";
	}
	free(ptr);
	return 0;
}