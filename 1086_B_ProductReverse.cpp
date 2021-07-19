#include<iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int product = m * n;
	char reversal[8];
	int i = 0, j = 0;
	while (product) {
		reversal[i++] = product % 10 + 48;
		product /= 10;
	}
	while (j < i - 1) {
		if (reversal[j] != '0') break;
		else j++;
	}
	for (; j < i; j++) cout << reversal[j];
	cout << endl;
	return 0;
}