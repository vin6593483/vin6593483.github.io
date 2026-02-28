#include<iostream>
#include<cstdlib>
using namespace std;
struct student {
	int id;
	int grade;
	student* next_student;
};
struct  classes {
	int students;
	student* first_student;
	classes* next_class;
};
classes* c;
student* s;
void add_student(int id, int grade) {
	if (c->students == 0) {
		c->first_student = NULL;
	}
	if (c->first_student == NULL) {
		c->first_student = (student*)malloc(sizeof(student));
		s = c->first_student;
	}
	else if (s->next_student == NULL) {
		s->next_student = (student*)malloc(sizeof(student));
		s = s->next_student;
	}
	s->id = id;
	s->grade = grade;
	s->next_student = NULL;
	c->students++;
}
void show(classes* class1) {
	int i = 1;
	classes* now_c = class1;
	student* now_s = s;
	for (now_c = class1; now_c != NULL; now_c = now_c->next_class, i++) {
		cout << "Class" << i << "(" << now_c->students << ")" << ":";
		for (now_s = now_c->first_student; now_s != NULL; now_s = now_s->next_student) {
			cout << now_s->id << "(" << now_s->grade << ")->";
		}
		cout << "NULL" << endl;
	}
}
int main() {
	int c1s1, c1s2, c1s3, c2s1, c2s2, c3s1, c3s2, c3s3;
	cin >> c1s1 >> c1s2 >> c1s3 >> c2s1 >> c2s2 >> c3s1 >> c3s2 >> c3s3;
	classes* class1 = (classes*)malloc(sizeof(classes));
	class1->students = 0;
	c = class1;
	add_student(1, c1s1);
	add_student(2, c1s2);
	add_student(3, c1s3);
	c->next_class = (classes*)malloc(sizeof(classes));
	c = c->next_class;
	c->students = 0;
	add_student(1, c2s1);
	add_student(2, c2s2);
	c->next_class = (classes*)malloc(sizeof(classes));
	c = c->next_class;
	c->students = 0;
	add_student(1, c3s1);
	add_student(2, c3s2);
	add_student(3, c3s3);
	c->next_class = NULL;
	show(class1);
	system("pause");
	return 0;
}
