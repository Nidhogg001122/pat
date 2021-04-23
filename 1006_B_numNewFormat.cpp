#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int num, format[3], i = 0, j;
	for (i = 0; i < 3; i++) format[i] = 0;
	i = 0;
	cin >> num;
	while (num > 0) {
		format[i++] = num % 10;
		num /= 10;
	}
	j = format[2];
	while (j-- > 0) cout << 'B';
	j = format[1];
	while (j-- > 0) cout << 'S';
	for (i = 1, j = format[0]; j > 0; i++, j--) cout << i;
	cout << endl;
	return 0;
}