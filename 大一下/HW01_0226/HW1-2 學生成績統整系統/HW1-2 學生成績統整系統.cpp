#include<iostream>
using namespace std;
struct student {
	char gender;
	float score;
};
int main(void) {
	student s[5];
	float boyscore = 0;
	float girlscore = 0;
	float boynum = 0;
	float girlnum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> s[i].gender;
		cin >> s[i].score;
		if (s[i].gender == 'b') {
			boynum++;
			boyscore = boyscore + s[i].score;
		}
		else {
			girlnum++;
			girlscore = girlscore + s[i].score;
		}
	}
	cout << boyscore / boynum << endl;
	cout << girlscore / girlnum;
	return 0;
}