# 作業 11-1：建立基本 Linked list (basic)

這題是資料結構的入門課——「鏈結串列 (Linked List)」。我們利用 `struct` 建立一個包含資料 (number) 與指向下一個結構指標 (next_struct) 的節點。透過將每個節點的指標指向下一個節點的地址，形成一條鏈結，並在最後一個節點放上 `NULL` 代表結束。

## 💡 程式碼與解題思路

詳細的節點定義與串列走訪邏輯，我都對齊在右側註解區供大家參考：

```cpp
#include<iostream>
using namespace std;
struct node {                                               // 定義節點結構
	int number;                                             // 存放資料的變數
	node* next_struct;                                      // 指向另一個 node 結構的指標（用來串接下一節）
};
int main(void) {                                            // 進入主程式
	node info[6];                                           // 宣告一個長度為 6 的 node 陣列作為串列空間
	for (int i = 0; i < 6; i++) {                           // 跑迴圈讀取資料並建立鏈結
		cin >> info[i].number;                             // 讀取使用者輸入的數值
		info[i].next_struct = &info[i + 1];                 // 核心：將當前節點的指標指向「下一個節點」的地址
	}
	info[5].next_struct = NULL;                             // 重要：最後一個節點後面沒人了，必須指向 NULL 代表終點
	node* ptr = &info[0];                                   // 宣告一個走訪指標 ptr，從頭節點 (index 0) 開始
	while (ptr != NULL) {                                   // 只要 ptr 還沒指到 NULL，就代表還沒走到終點
		cout << ptr->number << "->";                        // 輸出當前節點的數值，並畫出箭頭圖示
		ptr = ptr->next_struct;                             // 關鍵：將指標更新為「下一個節點的位址」，往後移動
	}
	cout << "NULL" << endl;                                 // 串列結束後輸出 NULL 並換行
	return 0;                                               // 程式順利結束
}
```
