#include<cstdio>
#include<iostream>
using namespace std;

int num[1000000][2] = { 0 };
int result[1000000][2] = { 0 };

int main() {
	int base, index,front=0;
	int i = 0;
	char c = 'a';
	while (c!='\n') {
		cin >> num[i][0];
		c = getchar();
		cin >> num[i][1];
		i++;
		c = getchar();
	}
	int j = 0;
	for (j = 0; j < i-1; j++) {
		base = num[j][0] * num[j][1];
		index = num[j][1] - 1;
		if (front != 0 && j != i - 2) printf(" ");
		if (base != 0) printf("%d %d", base, index);
		front = base;
	}
	base = num[j][0] * num[j][1];
	index = num[j][1] - 1;
	if (base != 0) printf(" %d %d\n", base, index);
	else(printf("\n"));
	return 0;
}