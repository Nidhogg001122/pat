#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int all,i;
	long num[11][3];
	cin >> all;
	for (i = 0; i < all; i++) {
		cin >> num[i][0] >> num[i][1] >> num[i][2];
	}
	for ( i = 0; i < all; i++) {
		if (num[i][0] + num[i][1] > num[i][2]) printf("Case #%d: true\n", i + 1);
		else printf("Case #%d: false\n", i + 1);
	}
	return 0;
}