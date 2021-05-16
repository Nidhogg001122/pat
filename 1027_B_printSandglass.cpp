#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int num, rem, count, i, j;
	char c;
	cin >> num >> c;
	num = num - 1;
	count = 1;
	i = 3;
	while (num) {
		int temp = num;
		temp -= 2 * i;
		if (temp >= 0) {
			num = temp;
			i += 2;
			count += 2;
		}
		else {
			rem = num;
			break;
		}
	}
	for (i = count; i > 0; i -= 2) {
		for (j = 0; j < (count - i) / 2; j++) printf(" ");
		for (j = 0; j < i; j++) printf("%c", c);
		printf("\n");
	}
	for (i = 3; i <= count; i += 2) {
		for (j = 0; j < (count - i) / 2; j++) printf(" ");
		for (j = 0; j < i; j++) printf("%c", c);
		printf("\n");
	}
	printf("%d\n", rem);
	return 0;
}