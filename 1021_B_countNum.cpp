#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

char num[10010];

int main() {
	int i, count[10];
	for (i = 0; i < 10; i++) count[i] = 0;
	cin >> num;
	char c;
	for (i = 0; i < strlen(num); i++) count[num[i] - 48]++;
	for (i = 0; i < 10; i++) {
		if (count[i]) cout << i << ':' << count[i] << endl;
	}
	return 0;
}