#include<iostream>
using namespace std;
class gun {
private:
	int bullet = 0;
public:
	void shoot() {
		if (bullet == 0) {
			cout << "Please Reload" << endl;
		}
		else {
			bullet--;
			cout << "Bang" << endl;
		}
	}
	void reload() {
		cout << "Reload" << endl;
		bullet = 3;
	}
};
int main(){
	char a[5];
	gun g1;
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	for (int i = 0; i < 5; i++) {
		if (a[i] == 's')
			g1.shoot();
		else if (a[i] == 'r')
			g1.reload();
	}
	return 0;
}