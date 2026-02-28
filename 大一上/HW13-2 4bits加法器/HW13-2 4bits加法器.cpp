#include<iostream>
#include<cstdlib>
using namespace std;
struct node {
	int n;
	node* next;
};
node* LIST(void) {
    node* head = NULL;
    node* current = NULL;
    int num;
    for (int i = 0; i < 4; i++) {
        cin >> num;
        node* input = (node*)malloc(sizeof(node));
        input->n = num;
        input->next = NULL;
        if (head == NULL) {
            head = input;
            current = input;
        }
        else {
            current->next = input;
            current = current->next;
        }
    }
    return head;
}
void ADD(node* list1, node* list2) {
    node* ptr1 = list1;
    node* ptr2 = list2;
    int c = 0;
    for (int i = 0; i < 4; i++) {
        int n1 = ptr1->n;
        int n2 = ptr2->n;
        int sum = n1 + n2 + c;
        int result = sum % 2;
        c = sum / 2;
        cout << result;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (c > 0) {
        cout << endl;
        cout << "overflow!";
    }
}
int main(void) {
    node* list1 = LIST();
    node* list2 = LIST();
    ADD(list1, list2);
    return 0;
}