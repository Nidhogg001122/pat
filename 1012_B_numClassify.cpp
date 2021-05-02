#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	int A1 = 0, A2[1001] = { 0 }, A3 = 0, A4 = 0, A5 = 0, numA4 = 0;
	int total, num;
	cin >> total;
	int i, j;
	for (i = 0, j = 0; i < total; i++) {
		cin >> num;
		if (num % 5 == 0 && num % 2 == 0) A1+=num;
		if (num % 5 == 1) A2[j++] = num;
		if (num % 5 == 2) A3++;
		if (num % 5 == 3) {
			A4 += num;
			numA4++;
		}
		if (num % 5 == 4 && num > A5) A5 = num;
	}
	if (A1) printf("%d", A1);
	else printf("N");
	if (A2[0]) {
		int sum = A2[0];
		for (i = 1; i < j; i++) {
			if (i % 2) sum -= A2[i];
			else sum += A2[i];
		}
		printf(" %d", sum);
	}
	else printf(" N");
	if (A3) printf(" %d", A3);
	else printf(" N");
	if (A4) {
		float average = 1.0 * A4 / numA4;
		printf(" %.1f", average);
	}
	else printf(" N");
	if (A5) printf(" %d\n", A5);
	else printf(" N\n");
	return 0;
}