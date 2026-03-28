#include<iostream>
using namespace std;
class list {
private:
	int arr[4];                                  //先創立4格的陣列存數字(題目是四個，如果有多可以用mollac的方式)
public:
	void set(int a, int b, int c, int d) {       //設定set函數的內容(看主程式確定是4輸入0輸出)
		arr[0] = a;                              //很原始的把輸入內容覆寫到我們list的陣列裡
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
	}
	list operator+(list arr2) {                  //運算子多載，這裡先來定義在這個class裡，+的新用法
		list arr3;                               //先創立一個list(因為我們定義了輸出是list)
		for (int i = 0; i < 4; i++) {            //把L1(本身)的數值跟L2(傳入)的數值相加，並賦值給L3
			arr3.arr[i] = arr[i] + arr2.arr[i];
		}
		return arr3;                             //回傳
	}
	list operator-(list arr2) {                  //這裡同理，定義了在這個class裡，-符號的新用法
		list arr4;
		for (int i = 0; i < 4; i++) {
			arr4.arr[i] = arr[i] - arr2.arr[i];
		}
		return arr4;
	}
	void show() {                                //輸出函數
		cout << arr[0];                          //我的想法是:先輸出第一個，後面的每一個都先輸出逗號再輸出數值
		for (int i = 1; i < 4; i++) {            //這樣就可以用到迴圈，又不會在最後多一個逗號了
			cout << "," << arr[i];
		}
		cout << endl;
	}
};
//---------以下是主程式---------
int main(){
	int n[8];
	list L1, L2, L3, L4;
	for (int i = 0; i < 8; i++){
		cin >> n[i];
	}
	L1.set(n[0], n[1], n[2], n[3]);
	L2.set(n[4], n[5], n[6], n[7]);
	L3 = L1 + L2;
	L4 = L1 - L2;
	L3.show();
	L4.show();
	return 0;
}
