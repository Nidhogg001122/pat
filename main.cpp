#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef struct data {
	char address[8];
	int num;
	char next[8];
}linkdata;

linkdata link[100010];
linkdata temp[100010];

int main() {
	int  total, change;
	char first[8];
	cin >> first >> total >> change;
	int i = 0, j = 0;
	for (i = 0; i < total; i++) cin >> temp[i].address >> temp[i].num >> temp[i].next;
	for (i = 0; i < total; i++) {
		if (!strcmp(temp[i].address, first)) {
			link[0] = temp[i];
			break;
		}
	}
	for (i = 0; i < total - 1; i++) {
		for (j = 0; j < total; j++) {
			if (!strcmp(temp[j].address, link[i].next)) {
				link[i + 1] = temp[j];
				break;
			}
		}
	}
	if(change) strcpy_s(link[0].next, link[change - 1].next);
	for (i = 1; i < change; i++) strcpy_s(link[i].next, link[i - 1].address);
	for (i = 0; i < change; i++) temp[i] = link[i];
	for (j = 0, i = change - 1; i >= 0; i--, j++) {
		strcpy_s(link[i].address, temp[j].address);
		strcpy_s(link[i].next, temp[j].next);
		link[i].num = temp[j].num;
	}
	for (i = 0; i < total; i++) cout << link[i].address << ' ' << link[i].num << ' ' << link[i].next << endl;
	return 0;
}