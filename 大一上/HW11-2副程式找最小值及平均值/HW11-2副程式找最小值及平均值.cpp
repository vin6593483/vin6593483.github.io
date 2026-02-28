#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
int min(node*ptr) {
	int mininum = ptr->data;
	while (ptr != NULL) {
		if (ptr->data < mininum) {
			mininum = ptr->data;
		}
		ptr = ptr->next;
	}
	return mininum;
}
float avg(node* ptr) {
	float sum = 0;
	while (ptr != NULL) {
		sum = sum + ptr->data;
		ptr = ptr->next;
	}
	float average = (sum / 5);
	return average;
}
int main(void) {
	node s1, s2, s3, s4, s5;
	cin >> s1.data >> s2.data >> s3.data >> s4.data >> s5.data;
	s1.next = &s2;
	s2.next = &s3;
	s3.next = &s4;
	s4.next = &s5;
	s5.next = NULL;
	cout << min(&s1) << " ";
	cout << avg(&s1) << endl;
	return 0;
}