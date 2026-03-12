#include<iostream>
using namespace std;
class person
{
private:
	int ID;
	string NAME;
public:
	void set_id(int id);
	void set_name(string name);
	int get_id(void);
	string get_name(void);
};
void person::set_id(int id) {
	ID = id;
}
void person::set_name(string name) {
	NAME = name;
}
int person::get_id(void) {
	return ID;
}
string person::get_name(void) {
	return NAME;
}
class student:public person {
private:
	float chinese;
	float math;
	float english;
public:
	student(int id,string name) {
		set_id(id);
		set_name(name);
	}
	void set_score(float a, float b, float c) {
		chinese = a;
		math = b;
		english = c;
	}
	void show(void) {
		cout << "中文:" << chinese << endl;
		cout << "數學:" << math << endl;
		cout << "英文:" << english << endl;
	}
	float average(void) {
		float avg = (chinese + math + english) / 3;
		return avg;
	}
	float average(float add) {
		float new_avg = ((chinese + math + english) / 3) + add;
		if (new_avg > 100) {
			new_avg = 100;
		}
		return new_avg;
	}
};
int main() 
{
	int id;
	string name;
	float chinese, math, english;
	char add_c;
	float add;
	cin >> name >> id >> chinese >> math >> english;
	student s1(id, name);
	s1.set_score(chinese, math, english);
	cout << s1.get_name() << endl;
	cout << s1.get_id() << endl;
	s1.show();
	cout << "平均成績:" << s1.average() << endl;
	cout << "是否加分(y/n):\n";
	cin >> add_c;
	if (add_c == 'y') {
		cout << "加分分數:\n";
		cin >> add;
		cout << "平均成績(加分後):" << s1.average(add) << endl;
	}
	return 0;
}
