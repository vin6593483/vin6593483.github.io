# 作業 13-2：4-bits 加法器

這題是 Linked List 在數位邏輯上的趣味應用。我們建立兩個長度為 4 的串列來模擬 4 位元的二進制數，並透過副程式進行逐位元相加。程式核心在於處理二進制的進位邏輯（sum % 2 與 sum / 2），並在最後判斷最高位元是否產生進位，藉此偵測「溢位 (Overflow)」現象。

## 💡 程式碼與解題思路

詳細的串列建立、二進制加法與溢位判斷邏輯，我都對齊在右側註解供大家參考：

```cpp
#include<iostream>
#include<cstdlib>
using namespace std;
struct node {                                               // 定義節點結構
	int n;                                                  // 存放位元數值 (0 或 1)
	node* next;                                             // 指向下一位元的指標
};
node* LIST(void) {                                          // 副程式：建立 4 位元的 Linked List
    node* head = NULL; node* current = NULL;
    int num;
    for (int i = 0; i < 4; i++) {                           // 跑迴圈讀取 4 個位元
        cin >> num;
        node* input = (node*)malloc(sizeof(node));          // 動態申請節點空間
        input->n = num; input->next = NULL;
        if (head == NULL) { head = input; current = input; } // 處理頭節點
        else { current->next = input; current = current->next; } // 串接後續位元
    }
    return head;                                            // 回傳串列頭地址
}
void ADD(node* list1, node* list2) {                        // 副程式：執行 4-bit 加法邏輯
    node* ptr1 = list1; node* ptr2 = list2;
    int c = 0;                                              // 宣告進位變數 c，初始為 0
    for (int i = 0; i < 4; i++) {                           // 逐位元進行相加
        int n1 = ptr1->n; int n2 = ptr2->n;                 // 取出兩組串列同位置的位元
        int sum = n1 + n2 + c;                              // 當前位元相加並加上前一位的進位
        int result = sum % 2;                               // 二進制結果：取 2 的餘數
        c = sum / 2;                                        // 計算新的進位：取 2 的商
        cout << result;                                     // 輸出該位元的加法結果
        ptr1 = ptr1->next; ptr2 = ptr2->next;               // 兩組指標同步移向下一位元
    }
    if (c > 0) {                                            // 如果最後最高位還有進位產生
        cout << endl << "overflow!";                        // 輸出溢位訊息
    }
}
int main(void) {                                            // 進入主程式
    node* list1 = LIST();                                   // 建立第一組 4-bit 串列
    node* list2 = LIST();                                   // 建立第二組 4-bit 串列
    ADD(list1, list2);                                      // 執行加法運算並顯示結果
    return 0;                                               // 程式結束
}
```
