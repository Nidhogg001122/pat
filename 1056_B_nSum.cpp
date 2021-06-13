#include<cstdio>
using namespace std;

int num[16];

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &num[i]);
	int sum = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (j != i) {
				sum += (10 * num[i] + num[j]);
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}