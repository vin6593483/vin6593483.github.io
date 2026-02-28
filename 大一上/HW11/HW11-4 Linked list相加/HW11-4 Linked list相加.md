# 作業 11-4：Linked list 相加

這題練習如何操作多個 Linked List 並進行邏輯運算。我們模擬了兩個三位數的加法：分別建立兩組長度為 3 的節點串列，讀取數值後進行對應位置的相加，並實作了手動進位 (Carry) 邏輯，最後將結果儲存在第三組串列中輸出。

## 💡 程式碼與解題思路

詳細的串列初始化、進位判斷與輸出邏輯，我都對齊在右側註解供大家參考：

```cpp
#include<iostream>
using namespace std;
struct node {                                               // 定義節點結構
	int n;                                                  // 存放數字
	node* next;                                             // 指向下一節的指標
};
int main(void) {                                            // 進入主程式
	node a1,a2,a3,b1,b2,b3;                                 // 手動宣告兩組串列所需的節點
	a1.n = a2.n = a3.n = 0; b1.n = b2.n = b3.n = 0;         // 初始化所有數值為 0
	a1.next = &a2; a2.next = &a3; a3.next = NULL;           // 串接第一組串列 A
	b1.next = &b2; b2.next = &b3; b3.next = NULL;           // 串接第二組串列 B
	for (node* p1 = &a1; p1 != NULL; p1 = p1->next) {       // 迴圈讀取第一組串列的數值
		cin >> p1->n;
	}
	for (node* p2 = &b1; p2 != NULL; p2 = p2->next) {       // 迴圈讀取第二組串列的數值
		cin >> p2->n;
	}
	for (node* p1 = &a1; p1 != NULL; p1 = p1->next) {       // 輸出串列 A 的內容
		cout << p1->n << "->";
	}
	cout << "NULL" << endl;
	for (node* p2 = &b1; p2 != NULL; p2 = p2->next) {       // 輸出串列 B 的內容
		cout << p2->n << "->";
	}
	cout << "NULL" << endl << endl;
	node c1, c2, c3;                                        // 宣告結果串列 C
	c1.n = c2.n = c3.n = 0; c1.next = &c2; c2.next = &c3; c3.next = NULL;
	
	c1.n = a1.n + b1.n;                                     // 第一位數相加
	if (c1.n >= 10) {                                       // 判斷是否進位
		c1.n = c1.n - 10; c2.n = c2.n + 1;                  // 目前位置扣 10，下一位加 1
	}
	c2.n = a2.n + b2.n + c2.n;                              // 第二位數相加（包含前位的進位）
	if (c2.n >= 10) {
		c2.n = c2.n - 10; c3.n = c3.n + 1;                  // 處理進位
	}
	c3.n = a3.n + b3.n + c3.n;                              // 第三位數相加
	if (c3.n >= 10) { c3.n = c3.n - 10; }                   // 處理最後一位的進位 (此題上限為三位)
	
	for (node* p3 = &c1; p3 != NULL; p3 = p3->next) {       // 輸出最終相加結果串列
		cout << p3->n << "->";
	}
	cout << "NULL";
	return 0;                                               // 程式順利結束
}
```
