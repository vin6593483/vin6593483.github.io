#include<iostream>
using namespace std;
class find_word {
public:
	int find(char x, char* a, int length) {
		int start = 0;
		int count = 0;
		for (int i = 0; i <= length; i++) {
			if (a[i] == ' ' || a[i] =='.') {
				for (int j = start; j < i; j++) {
					if (a[j] == x) {
						 count++;
						 for (int k = start; k < i; k++) {
							cout << a[k];
						 }
						 cout << endl;
						 break;
					}
				}
				start = i + 1;
			}
		}
		return count;
	}
};
int main() {
	char a[] = "I am John. I love apple and water.";
	int length = sizeof(a);
	char x;
	cin >> x;
	find_word f1;
	cout << f1.find(x, a, length) << endl;
	return 0;
}