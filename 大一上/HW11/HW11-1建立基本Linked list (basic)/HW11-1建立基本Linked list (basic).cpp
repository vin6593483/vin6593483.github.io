#include<iostream>
using namespace std;
struct node {
	int number;
	node* next_struct;
};
int main(void) {
	node info[6];
	for (int i = 0; i < 6; i++) {
		cin >> info[i].number;
		info[i].next_struct = &info[i + 1];
	}
	info[5].next_struct = NULL;
	node* ptr = &info[0];
	while (ptr != NULL) {
		cout << ptr->number << "->";
		ptr = ptr->next_struct;
	}
	cout << "NULL" << endl;
	return 0;

}
