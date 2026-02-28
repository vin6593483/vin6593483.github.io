#include<iostream>
using namespace std;
int main(void) {
	int a;
	cin >> a;                     //先讓使用者輸入要計算的數
	int i;                        //建立for計算值
	for (i = 1; i <= a; i++) {    //for(從1開始;到a停止;i每走完一圈+1)，i會從1開始加，每一次迴圈i都會比前一個迴圈大1值到加到a為止
		if (a % i == 0) {         //迴圈裡的判斷內容:把每一次迴圈的i都拿去除a，要是餘數是0，那就輸出，並在後面加空格(題目要求)
			cout << i << " ";
		}
	}
	return 0;                     //重設所有記憶體狀態
}
