#include<iostream>
using namespace std;
class person {
private:
	int high;
	int weight;
public:
	void setup(int m,int n) {
		high = m;
		weight = n;
	}
	void show() {
		if (high < 0 || weight < 0) {
			cout << "他不是人" << endl;
		}
		else {
			cout << "身高" << high << endl;
			cout << "體重" << weight << endl;
		}
	}
};
int main() {
	person p[2];
	int h1, w1, h2, w2;
	cin >> h1 >> w1 >> h2 >> w2;
	p[0].setup(h1, w1);
	p[1].setup(h2, w2);
	for (int i = 0; i < 2; i++) {
		cout << "第" << i + 1 << "位:\n";
		p[i].show();
	}
	return 0;
}