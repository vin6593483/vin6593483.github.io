# 作業 13-1：Linked List 加入節點

這題練習 Linked List 的動態擴充。我們首先建立一個初始頭節點，接著利用 `while` 迴圈持續讀取使用者輸入，每讀到一個有效數字就利用 `malloc` 申請一個新節點並串接到當前串列的末端。這展現了 Linked List 在處理長度未知資料時的靈活性。

## 💡 程式碼與解題思路

詳細的動態節點申請與指標位移邏輯，我都對齊在右側註解牆供大家參考：

```cpp
#include<iostream>
using namespace std;
struct node {                                               // 定義節點結構
	int n;                                                  // 存放數值
	node* next;                                             // 指向下一節的指標
};
int main(void) {                                            // 進入主程式
	node* first = (node*)malloc(sizeof(node));              // 申請第一個節點的記憶體
	first->n = 1;                                           // 初始化首個節點數值為 1
	first->next = NULL;                                     // 首個節點目前後方無人
	node* p = first;                                        // 指標 p 用來紀錄目前串列的最尾端
	int num;
	while (cin >> num && 0 < num && num < 1000) {           // 當輸入數字在 1~999 之間時繼續增加節點
		node* input = (node*)malloc(sizeof(node));          // 申請新節點空間
		p->next = input;                                    // 核心：將目前末端指標指向新節點
		input->n = num;                                     // 存入輸入的數值
		input->next = NULL;                                 // 新節點暫時作為末端
		p = input;                                          // 更新指標 p 到新的末端，準備下一次串接
	}
	if (num == 0) {                                         // 如果輸入為 0，代表輸入結束並開始輸出
		for (node* c = first; c != NULL; c = c->next) {     // 利用走訪指標 c 從頭開始巡視
			cout << c->n << "->";                           // 依序輸出數值與箭頭符號
		}
	}
	cout << "NULL";                                         // 最後標示 NULL 代表串列結束
	return 0;                                               // 程式順利結束
}
```
