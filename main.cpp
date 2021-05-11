#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef struct data {
	int address, num, next;
}linkdata;

linkdata link[100010];
linkdata temp[100010];

int main() {
	int  total, change;
	linkdata mid;
	int first;
	if (!scanf("%d %d %d", &first, &total, &change)) return -1;
	int i = 0, j = 0, k = 0;
	while (i < total) {
		scanf("%d", &j);
		scanf("%d %d", &temp[j].num, &temp[j].next);
		i++;
	}
	for (j = 0, i = first; j < total; j++) {
		link[j].address = i;
		link[j].num = temp[i].num;
		if (j + 1 == change) {
			for (k = 0; k < change / 2; k++) {
				mid = link[j - k];
				link[j - k] = link[k];
				link[k] = mid;
			}
		}
		if (temp[i].next == -1) break;
		i = temp[i].next;
	}
	for (k = 0; k < j; k++) {
		printf("%05d %d %05d\n", link[k].address, link[k].num, link[k + 1].address);
	}
	printf("%5d %d -1\n", link[k].address, link[k].num);
	return 0;
}