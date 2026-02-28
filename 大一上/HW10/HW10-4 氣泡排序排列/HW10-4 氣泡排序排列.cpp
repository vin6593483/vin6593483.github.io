#include<iostream>
#include<cstdlib>
using namespace std;
void sort(int* arr,int n) {
	for (int i = 0; i < n-1 ; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main(void) {
	int n;
	cin >> n;
	int* arr;
	arr = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr,n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;

}
