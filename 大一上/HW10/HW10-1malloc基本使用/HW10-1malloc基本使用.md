# 作業 10-1：malloc 基本使用

這題是關於「動態記憶體配置」的實作。我們利用 `malloc` 根據使用者輸入的 `n` 向系統申請一塊浮點數空間，並透過指標運算來存取資料。題目要求對偶數索引位置的數值加 3，奇數索引則乘 2，最後別忘了使用 `free` 歸還記憶體，這是避免記憶體洩漏 (Memory Leak) 的重要步驟。

## 💡 程式碼與解題思路

動態申請與指標算術的細節，我都詳細對齊在右側註解區了：

```cpp
#include<iostream>
using namespace std;
int main(void) {
	int n;                                                      // 宣告變數 n 用來儲存想要申請的資料數量
	cin >> n;                                                   // 讀取數量
	float* ptr;                                                 // 宣告一個浮點數指標 ptr
	ptr = (float*)malloc(n * sizeof(float));                    // 核心：動態申請 n 個 float 大小的空間，並強制轉型存入 ptr
	for (int i = 0; i < n; i++) {                               // 迴圈讀取輸入資料
		cin >> *(ptr + i);                                      // 利用指標偏移 (Pointer Arithmetic) 依序存入數值
	}
	for (int i = 0; i < n; i++) {                               // 跑迴圈處理數據運算
		if (i % 2 == 0) {                                       // 如果索引 i 是偶數 (0, 2, 4...)
			*(ptr + i) = *(ptr + i) + 3;                        // 該位置的數值加 3
		}
		else {                                                  // 如果索引 i 是奇數 (1, 3, 5...)
			*(ptr + i) = *(ptr + i) * 2;                        // 該位置的數值乘 2
		}
	}
	for (int i = 0; i < n; i++) {                               // 迴圈輸出處理後的結果
		cout << *(ptr + i) << " ";                              // 依序輸出數值並以空格分隔
	}
	free(ptr);                                                  // 重要：程式結束前使用 free 釋放動態申請的記憶體
	return 0;                                                   // 程式結束
}
```
