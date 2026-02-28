#include<iostream>
using namespace std;
struct node {
	int n;
	node* next;
};
int main(void) {
	node* first = (node*)malloc(sizeof(node));
	first->n = 1;
	first->next = NULL;
	node* p = first;
	int num;
	while (cin >> num && 0 < num && num < 1000) {
		node* input = (node*)malloc(sizeof(node));
		p->next = input;
		input->n = num;
		input->next = NULL;
		p = input;
	}
	if (num == 0) {
		for (node* c = first; c != NULL; c = c->next) {
			cout << c->n << "->";
		}
	}
	cout << "NULL";
	return 0;

}
