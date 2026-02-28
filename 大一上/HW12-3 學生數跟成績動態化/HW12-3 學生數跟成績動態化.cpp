#include<iostream>
#include<cstdlib>
using namespace std;
struct student {
	int id;
	float grade;
	student* next;
};
struct classes {
	int students;
	student* first_student;
	classes* next;
};
void add_student(classes* current, int id, float grade) {
	student* new_s = (student*)malloc(sizeof(student));
	new_s->id = id;
	new_s->grade = grade;
	new_s->next = NULL;
	if (current->first_student==NULL) {
		current->first_student = new_s;
	}
	else {
		student* temp = current->first_student;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_s;
	}
}
void show(classes* head) {
	int i = 1;
	for (classes* p = head; p != NULL; p = p->next, i++ ) {
		cout << "Class" << i << "(" << p->students << "):";
		for (student* s = p->first_student; s != NULL; s = s->next) {
			cout << s->id << "(" << s->grade << ")->";
		}
		cout << "NULL" << endl;
	}
}
int main(void) {
	int n;
	cin >> n;
	classes* head = NULL;
	classes* current = NULL;
	for (int i = 0; i < n; i++) {
		classes* newnode = (classes*)malloc(sizeof(classes));
		newnode->first_student = NULL;
		newnode->students = 0;
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
			current = newnode;
		}
		else {
			current->next = newnode;
			current = newnode;
		}
		int m;
		cin >> m;
		current->students = m;
		for (int j = 0; j < m; j++) {
			float grade;
			cin >> grade;
			add_student(current, j + 1, grade);
		}
	}
	show(head);
	return 0;
}