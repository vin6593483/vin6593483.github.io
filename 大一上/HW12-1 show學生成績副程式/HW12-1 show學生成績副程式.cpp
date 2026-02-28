#include<iostream>
#include<cstdlib>
using namespace std;
struct student {
	int id;
	int grade;
	student* next_student;
};
struct  classes {
	student* first_student;
	classes* next_class;
};
classes* c;
student* s;
void show(classes* class1) {
	int i = 1;
	for (c = class1; c != NULL; c = c->next_class, i++) {
		cout << "Class" << i << ":";
		for (s = c->first_student; s != NULL; s = s->next_student) {
			cout << s->id << "(" << s->grade << ")->";
		}
		cout << "NULL" << endl;
	}
}
int main() {
	classes* class1 = (classes*)malloc(sizeof(classes));
	// class 1 add students (id,grade)
	c = class1;
	c->first_student = (student*)malloc(sizeof(student));
	s = c->first_student;
	s->grade = 100;
	s->id = 1;
	s->next_student = (student*)malloc(sizeof(student));
	s = s->next_student;
	s->grade = 90;
	s->id = 2;
	s->next_student = (student*)malloc(sizeof(student));
	s = s->next_student;
	s->grade = 80;
	s->id = 3;
	s->next_student = NULL;
	// class 2 add students (id,grade)
	c->next_class = (classes*)malloc(sizeof(classes));
	c = c->next_class;
	c->first_student = (student*)malloc(sizeof(student));
	s = c->first_student;
	s->grade = 75;
	s->id = 1;
	s->next_student = (student*)malloc(sizeof(student));
	s = s->next_student;
	s->grade = 65;
	s->id = 2;
	s->next_student = NULL;
	// class 3 add students (id, grade)
	c->next_class = (classes*)malloc(sizeof(classes));
	c = c->next_class;
	c->first_student = (student*)malloc(sizeof(student));
	s = c->first_student;
	s->grade = 53;
	s->id = 1;
	s->next_student = (student*)malloc(sizeof(student));
	s = s->next_student;
	s->grade = 43;
	s->id = 2;
	s->next_student = (student*)malloc(sizeof(student));
	s = s->next_student;
	s->grade = 33;
	s->id = 3;
	s->next_student = NULL;
	c->next_class = NULL;
	// show all students' grade
	show(class1);
	system("pause");
	return 0;
}