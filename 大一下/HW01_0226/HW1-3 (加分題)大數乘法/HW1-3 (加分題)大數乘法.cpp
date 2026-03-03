#include<iostream>
using namespace std;
int main(void) {
	//被乘數
	int n = 0;
	cin >> n;
	int* arr1 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		arr1[i] = 0;
	}
	for (int i = n-1; i >= 0; i--) {
		cin >> arr1[i];
	}
	if (arr1[n-1] == 0) {
		cout << "最高位不可為0!";
		return 0;
	}
	//乘數
	int m = 0;
	cin >> m;
	int* arr2 = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		arr2[i] = 0;
	}
	for (int i = m-1; i >= 0; i--) {
		cin >> arr2[i];
	}
	if (arr2[m-1] == 0) {
		cout << "最高位不可為0!";
		return 0;
	}
	//積
	int* sum = (int*)malloc((m + n) * sizeof(int));
	for (int k = 0; k < (m + n); k++) {
		sum[k] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum[i + j] = sum[i + j] + arr1[i] * arr2[j];
		}
	}
	//進位
	for (int i = 0; i < (m + n - 1); i++) {
		sum[i + 1] = sum[i + 1] + (sum[i] / 10);
		sum[i] = sum[i] % 10;
	}
	int check = 0;
	for (int i = (m + n - 1); i >= 0; i--) {
		if (check == 0 && sum[i] == 0) {
			check++;
		}
		else {
			cout << sum[i];
		}
	}
	free(arr1);
	free(arr2);
	free(sum);
	return 0;

}
