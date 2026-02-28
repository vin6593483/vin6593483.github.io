# 作業 6-2：BMI 整合系統

這題結合了 `struct` (結構) 與 BMI 計算。我們將學生的性別、身高、體重與 BMI 值打包在一起管理，先透過迴圈將身高轉換單位並計算出 BMI，接著再統計 BMI 大於 24 的男女人數，最後比較哪一個性別超標的人數比較多。

## 💡 程式碼與解題思路

直觀的解法就是好解法！詳細的邏輯與內心戲都整理在右側的註解了：

```cpp
#include<iostream>                                                                     // 先疊個甲，我的每一題肯定不是最優解，我只是用比較直觀的方式在作答，畢竟看懂最重要
using namespace std;
struct student {                                                                       // 一樣先建立struct結構
	char gender;                                                                       // 性別欄，字符格式
	float height;                                                                      // 身高跟體重我都用浮點數，避免有人身高輸入的時候有打小數
	float weight;
	float bmi;                                                                         // 這欄其實是我後面加的，我本來只是想單純的輸出bmi(直接讓電腦現算)，結果發現太麻煩了，所以回來加這欄，到時候資料直接存這裡面可以隨意調用
};
int main(void) {                                                                       // 進入主程式
	student s[5];                                                                      // 題目說5筆資料，所以先建立5格的student結構的陣列
	for (int i = 0; i < 5; i++) {                                                      // for迴圈讓使用者輸入資料
		cin >> s[i].gender >> s[i].height >> s[i].weight;                              // 記住此時的身高是公分制
	}
	for (int i = 0; i < 5; i++) {                                                      // 現在換我們輸出bmi在螢幕上
		s[i].height = s[i].height / 100;                                               // 首先在這個for迴圈內把身高先除100，變成公尺制
		s[i].bmi = s[i].weight / (s[i].height * s[i].height);                          // 當然也可以直接在這行做處理，我只是不想有那麼多括號(眼睛不好)
		cout << s[i].bmi << "\n";                                                      // 輸出!(記得換行)
	}
	int boycount = 0, girlcount = 0;                                                   // 接下來的計數環節依舊土法煉鋼，建立負責記錄人數的記憶體
	for (int i = 0; i < 5; i++) {                                                      // 跟上一題一樣，只要bmi大於24且性別為男的，就把計男生的記憶體加一
		if (s[i].bmi > 24 && s[i].gender == 'b') {
			boycount++;
		}
		else if (s[i].bmi > 24 && s[i].gender == 'g') {                                // 女生重複一次
			girlcount++;
		}
	}
	if (boycount > girlcount) {                                                        // 進入互比環節
		cout << "boy";
	}
	else if (boycount < girlcount) {
		cout << "girl";
	}
	else if (boycount == girlcount) {                                                   // 偷偷提醒：這裡做條件判斷應該要用 == 喔！
		cout << "equal";
	}
	return 0;                                                                          // (殘酷天使的行動綱領好聽
}
```
