#include<iostream>
using namespace std;
struct node {
	int num;
	node* next_num;
};
int FIND(int n,node*ptr) {
	int goal = 0;
	while (ptr != NULL) {
		if (ptr->num == n) {
			goal++;
		}
		ptr = ptr->next_num;
	}
	return goal;
}
void ADD(node*first, int n,node*n_add) {
	node* ptr = first;
	while (ptr != NULL && ptr->num != n) {
		ptr = ptr->next_num;
	}
	if (ptr != NULL && ptr->num == n) {
		n_add->next_num = ptr->next_num;
		ptr->next_num = n_add;
		for (node* p = first; p != NULL; p = p->next_num) {
			cout << p->num << "->";
		}
		cout << "NULL";
	}
}
void DEL(node* first, int d) {
	if (first->num == d) {
		for (node* p = first->next_num; p != NULL; p = p->next_num) {
			cout << p->num << "->";
		}
		cout << "NULL";
		return;
	}
	node* ptr = first;
	node* last = NULL;
	while (ptr != NULL && ptr->num != d) {
		last = ptr;
		ptr = ptr->next_num;
	}

	if (ptr != NULL && ptr->num == d) {
		last->next_num = ptr->next_num;
		for (node* p = first; p != NULL; p = p->next_num) {
			cout << p->num << "->";
		}
		cout << "NULL";
	}
}
int main(void) {
	node n1, n2, n3, n4, n5;
	node n_add;
	n1.num = 1;
	n2.num = 2;
	n3.num = 3;
	n4.num = 4;
	n5.num = 5;
	n1.next_num = &n2;
	n2.next_num = &n3;
	n3.next_num = &n4;
	n4.next_num = &n5;
	n5.next_num = NULL;
	for (node* p = &n1; p != NULL; p = p->next_num) {
		cout << p->num << "->";
	}
	cout << "NULL" << endl;
	char input;
	cin >> input;
	while (input != 'a' && input != 'd') {
		cout << "無此指令";
		return 0;
	}
	if (input == 'a') {
		int n = 0, m = 0;
		cin >> n >> m;
		if (FIND(n, &n1) == 0) {
			cout << "查無此數字";
			return 0;
		}
		n_add.num = m;
		ADD(&n1, n, &n_add);
		return 0;
	}
	if (input == 'd') {
		int d = 0;
		cin >> d;
		if (FIND(d, &n1) == 0) {
			cout << "查無此數字";
			return 0;
		}
		DEL(&n1, d);
		return 0;
	}
}