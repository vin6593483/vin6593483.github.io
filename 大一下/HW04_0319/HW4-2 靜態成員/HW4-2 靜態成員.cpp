#include<iostream>
using namespace std;
class member {
private:
	char level;
	int id;
public:
	static int count;
	static int vip_count;
	member() {
    //空著是因為真的沒啥該建構的，要初始化的count因為是靜態成員所以得在類型外初始化(但要在類型內宣告)
	}
	member(int a, char b) {
		id = a;
		level = b;
		count++;
		if (b == 'v') {
			vip_count++;
		}
	}
	void show_inf() {
		cout << "總會員人數:" << count << endl;
		cout << "VIP會員人數:" << vip_count << endl;
	}
	static void show_fee() {
		int sum = (count - vip_count) * 300 + (vip_count * 500);
		cout << "總共會費:" << sum << "$" << endl;
	}
};
int member::count = 0;
int member::vip_count = 0;
int main(){
	int a[5];
	char b[5];
	for (int i = 0; i < 5; i++){
		cin >> a[i] >> b[i];
	}
	member p1(a[0], b[0]), p2(a[1], b[1]), p3(a[2], b[2]), p4(a[3], b[3]), p5(a[4], b[4]);
	p1.show_inf();
	member::show_fee();   //題目主程式小陷阱:主程式使用了 member::show_fee() 這種"類別名稱::函數"的呼叫方式，不得不將函數宣告為 static，否則編譯器會因為找不到實體物件而報錯
	return 0;
}