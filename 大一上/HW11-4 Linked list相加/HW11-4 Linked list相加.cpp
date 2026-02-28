#include<iostream>
using namespace std;
struct node {
	int n;
	node* next;
};
int main(void) {
	node a1,a2,a3,b1,b2,b3;
	a1.n = a2.n = a3.n = 0;
	b1.n = b2.n = b3.n = 0;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = NULL;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = NULL;
	for (node* p1 = &a1; p1 != NULL; p1 = p1->next) {
		cin >> p1->n;
	}
	for (node* p2 = &b1; p2 != NULL; p2 = p2->next) {
		cin >> p2->n;
	}
	for (node* p1 = &a1; p1 != NULL; p1 = p1->next) {
		cout << p1->n << "->";
	}
	cout << "NULL" << endl;
	for (node* p2 = &b1; p2 != NULL; p2 = p2->next) {
		cout << p2->n << "->";
	}
	cout << "NULL" << endl << endl;
	node c1, c2, c3;
	c1.n = c2.n = c3.n = 0;
	c1.next = &c2;
	c2.next = &c3;
	c3.next = NULL;
	c1.n = a1.n + b1.n;
	if (c1.n >= 10) {
		c1.n = c1.n - 10;
		c2.n = c2.n + 1;
	}
	c2.n = a2.n + b2.n + c2.n;
	if (c2.n >= 10) {
		c2.n = c2.n - 10;
		c3.n = c3.n + 1;
	}
	c3.n = a3.n + b3.n + c3.n;
	if (c3.n >= 10) {
		c3.n = c3.n - 10;
	}
	for (node* p3 = &c1; p3 != NULL; p3 = p3->next) {
		cout << p3->n << "->";
	}
	cout << "NULL";
	return 0;
}