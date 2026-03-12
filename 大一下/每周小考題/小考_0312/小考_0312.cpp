#include<iostream>
using namespace std;
class hamster {
private:
	int weight;
public:
	void set_weight(int w) {
		weight = w;
	}
	void exercise(int e) {
		weight = weight - e;
	}
	void eat(int f) {
		weight = weight + f;
	}
	void show(void) {
		cout << "Bibo現在" << weight << "公克" << endl;
	}
};
int main() {
	hamster bibo;
	int w, f, e;
	cin >> w >> f >> e;
	bibo.set_weight(w);
	bibo.eat(f);
	bibo.exercise(e);
	bibo.show();
	return 0;
}