# 作業 11-1：建立基本 Linked list (hard)

這題是 Linked List 的進階練習。我們利用結構陣列來模擬記憶體空間，並透過指標將每個元素串接起來。雖然在輸出時使用了陣列遍歷，但核心概念依然在於如何將 `next_struct` 指向正確的記憶體位址，並在結尾處正確標示 `NULL`。

## 💡 程式碼與解題思路

詳細的結構串接與輸出邏輯，我都對齊在右側註解區供大家參考：

```cpp
#include<iostream>
using namespace std;
struct node {                                               // 定義節點結構
	int number;                                             // 存放資料的變數
	node* next_struct;                                      // 指向下一節 node 結構的指標
};
int main(void) {                                            // 進入主程式
	node info[6];                                           // 宣告長度為 6 的 node 陣列作為靜態記憶體空間
	for (int i = 0; i < 6; i++) {                           // 跑迴圈讀取資料並建立鏈結關係
		cin >> info[i].number;                             // 讀取使用者輸入的數值
		info[i].next_struct = &info[i + 1];                 // 核心：將當前節點指標指向「下一個索引」的地址
	}
	info[5].next_struct = NULL;                             // 重要：最後一個節點必須指向 NULL 代表串列結束
	for (int i = 0; i < 6; i++) {                           // 跑迴圈依序輸出陣列中的內容
		cout << info[i].number;                             // 輸出當前節點的數值
		cout << "->";                                       // 輸出箭頭符號表示串連關係
	}
	cout << "NULL";                                         // 最後輸出 NULL 標示終點
	return 0;                                               // 程式順利結束
}
```
