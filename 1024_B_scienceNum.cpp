#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char num[10010] = { 'a' }, decimal[10010] = { 'a' }, E[10010];

int main() {
	cin >> num;
	int i = 0, j = 0, k = 0, index = 0;
	char integer = num[1];
	char c, judge = num[0];
	for (i = 3; i < strlen(num); i++) {
		if (num[i] != 'E') decimal[j++] = num[i];
		else break;
	}
	for (i = i + 1; i < strlen(num); i++) E[k++] = num[i];
	for (i = 1; i < k; i++) index = index * 10 + E[i] - 48;
	if (E[0] == '+') {
		num[0] = integer;
		for (i = 1, k = 0; k < index; k++) {
			if (k < j) num[i++] = decimal[k];
			else num[i++] = '0';
		}
		if (k < j) {
			num[i++] = '.';
			for (; k < j; k++) {
				num[i++] = decimal[k];
			}
		}
	}
	else {
		i = 0;
		if (index) {
			num[0] = '0';
			num[1] = '.';
			for (i = 2, k = 1; k < index; k++) num[i++] = '0';
		}
		num[i++] = integer;
		for (k = 0; k < j; k++) num[i++] = decimal[k];
	}
	if (judge == '-') printf("%c", judge);
	for (k = 0; k < i; k++) printf("%c", num[k]);
	printf("\n");
	return 0;
}