# 作業 10-1：物件指標練習 — BMI 計算系統 (Object Pointer & Dynamic Allocation)

這題把大一上學過的「類別封裝」與「指標、動態記憶體配置」揉在一起，是物件導向的進階練習。我們定義一個 `student` 類別把身高、體重、BMI 包成私有資料，再用 `new` 在記憶體動態開出一塊學生物件陣列，並透過「物件指標」來存取每個物件。重點在於理解：物件配置在記憶體後，指標怎麼用陣列索引的方式去操作它。

## 🔍 核心觀念解析

### 1. 物件指標與動態配置
* **`new student[n]`**：在執行階段才決定要開幾個學生物件，並回傳這塊連續記憶體的起始地址。這比固定大小的陣列更彈性，人數由使用者輸入決定。
* **指標當陣列用**：函數 `set_student` 回傳的是 `student*` 指標，但因為它指向一塊連續空間，所以可以像陣列一樣用 `ptr[i]` 存取第 i 個物件，再透過 `.` 呼叫它的成員函數。

### 2. 類別的封裝與運算
* **私有屬性 `high`、`weight`、`BMI`**：外部無法直接讀寫，必須經由 `setdata()` 寫入、`get_BMI()` 讀出，這就是封裝的精神。
* **BMI 公式**：`體重 / (身高公尺)²`。因為輸入身高單位是公分，所以先 `/100` 換成公尺再平方，計算結果直接存在私有成員裡，之後要輸出再呼叫 getter 取出。

---

## 💡 完整程式碼

```cpp
#include<iostream>
using namespace std;
class student {                                              // 定義學生類別
private:                                                     // 私有成員區，封裝內部資料
	float high;                                              // 身高（公分）
	float weight;                                            // 體重（公斤）
	float BMI;                                               // 計算後的 BMI 值
public:                                                      // 公開成員區
	void setdata(float a, float b) {                        // 設定資料並同時計算 BMI
		high = a;                                            // 儲存身高
		weight = b;                                          // 儲存體重
		BMI = weight / ((high / 100) * (high / 100));        // BMI = 體重 / (身高公尺)²，先除 100 把公分換成公尺
	}
	float get_BMI() {                                        // 取得 BMI 的介面函數（getter）
		return BMI;                                          // 回傳私有成員 BMI
	}
};
student* set_student(int n) {                                // 自訂函數：動態建立 n 個學生物件，回傳物件指標
	student* ptr = new student[n];                           // 使用 new 在記憶體配置一塊連續的 student 陣列，回傳起始地址
	for (int i = 0; i < n; i++) {                            // 依序讀取每位學生的資料
		float a, b;                                          // 暫存身高與體重
		cin >> a;                                            // 讀取身高
		cin >> b;                                            // 讀取體重
		ptr[i].setdata(a, b);                                // 透過指標以陣列索引存取物件，呼叫 setdata 寫入資料
	}
	return ptr;                                              // 回傳這塊動態陣列的起始指標
}
int main() {
	int num;                                                 // 學生人數
	cin >> num;                                              // 讀取學生人數
	student* s = set_student(num);                           // 接收函數回傳的物件指標，s 指向動態配置的陣列
	for (int i = 0; i < num; i++) {                          // 依序輸出每位學生的 BMI
		cout << "第" << i + 1 << "位同學的BMI: " << s[i].get_BMI() << endl;   // 用指標索引取出物件並呼叫 get_BMI
	}
	system("pause");                                         // 暫停畫面（Windows 環境）
	return 0;
}
```
