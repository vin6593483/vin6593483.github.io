#include<iostream>
using namespace std;
int rt_light_state(int a, int b) {
	int i = a ^ b;
	return i;
}
void Light_ONorOFF(int n) {
	if (n == 1) {
		cout << "light On\n";
	}
	else if (n == 0) {
		cout << "light Off\n";
	}
	else {
		cout << "error!!\n";
	}
}
int main(void) {
	int bt_A, bt_B, light_result;
	cin >> bt_A >> bt_B;
	light_result = rt_light_state(bt_A, bt_B);
	Light_ONorOFF(light_result);

	return 0;
}
