#include<iostream>
using namespace std;
int main(void) {
	int score;
	char name[100];
	cin >> name >> score;
	if (score > 100) {
		score = 100;
	}
	cout << "Name:" << name << "\n";
	cout << "Score:" << score << "\n";
	if (score < 60) {
		cout << name << " failed.";
	}
	else {
		cout << name << " passed.";
	}
	return 0;
}