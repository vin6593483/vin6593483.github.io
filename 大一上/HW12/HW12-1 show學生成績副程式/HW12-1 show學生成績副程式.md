# 作業 12-1：show 學生成績副程式 (Nested Linked List)

這題是鏈結串列的進階實作，展示了「巢狀結構」的概念。我們建立了兩層 Linked List：外層是班級 (`classes`)，每一節班級節點都指向一個內層的學生 (`student`) 串列。透過這種結構，我們可以動態地管理多個班級以及各班級內不同數量的學生。

## 💡 程式碼與解題思路

詳細的雙重指標走訪與動態記憶體申請邏輯，我都對齊在右側註解供大家參考：

```cpp
#include<iostream>
#include<cstdlib>
using namespace std;
struct student {                                            // 定義學生節點
	int id;                                                 // 學生學號
	int grade;                                              // 學生成績
	student* next_student;                                  // 指向同班級的下一個學生
};
struct  classes {                                           // 定義班級節點
	student* first_student;                                 // 指向該班級的第一位學生 (進入內層串列)
	classes* next_class;                                    // 指向同學校的下一個班級 (外層串列移動)
};
classes* c;                                                 // 全域變數：班級走訪指標
student* s;                                                 // 全域變數：學生走訪指標
void show(classes* class1) {                                // 副程式：顯示所有班級與學生成績
	int i = 1;                                              // 班級編號計數
	for (c = class1; c != NULL; c = c->next_class, i++) {   // 外層迴圈：走訪每一個班級
		cout << "Class" << i << ":";                        // 輸出目前班級編號
		for (s = c->first_student; s != NULL; s = s->next_student) { // 內層迴圈：走訪該班級內的所有學生
			cout << s->id << "(" << s->grade << ")->";      // 輸出學生學號與成績
		}
		cout << "NULL" << endl;                             // 班級學生串列結束
	}
}
int main() {                                                // 進入主程式
	classes* class1 = (classes*)malloc(sizeof(classes));    // 建立第一個班級的記憶體空間
	// Class 1 加入學生 (100, 90, 80 分)
	c = class1;
	c->first_student = (student*)malloc(sizeof(student));   // 申請第一位學生空間
	s = c->first_student; s->grade = 100; s->id = 1;
	s->next_student = (student*)malloc(sizeof(student));    // 申請第二位學生空間
	s = s->next_student; s->grade = 90; s->id = 2;
	s->next_student = (student*)malloc(sizeof(student));    // 申請第三位學生空間
	s = s->next_student; s->grade = 80; s->id = 3;
	s->next_student = NULL;                                 // 第一班學生結束
	// Class 2 加入學生 (75, 65 分)
	c->next_class = (classes*)malloc(sizeof(classes));      // 申請第二個班級空間
	c = c->next_class;
	c->first_student = (student*)malloc(sizeof(student));   // 申請二班第一位學生
	s = c->first_student; s->grade = 75; s->id = 1;
	s->next_student = (student*)malloc(sizeof(student));    // 申請二班第二位學生
	s = s->next_student; s->grade = 65; s->id = 2;
	s->next_student = NULL;
	// Class 3 加入學生 (53, 43, 33 分)
	c->next_class = (classes*)malloc(sizeof(classes));      // 申請第三個班級空間
	c = c->next_class;
	c->first_student = (student*)malloc(sizeof(student));
	s = c->first_student; s->grade = 53; s->id = 1;
	s->next_student = (student*)malloc(sizeof(student));
	s = s->next_student; s->grade = 43; s->id = 2;
	s->next_student = (student*)malloc(sizeof(student));
	s = s->next_student; s->grade = 33; s->id = 3;
	s->next_student = NULL;
	c->next_class = NULL;                                   // 所有班級串接結束
	
	show(class1);                                           // 呼叫副程式展現成果
	system("pause");                                        // 暫停畫面以便觀察
	return 0;
}
```
