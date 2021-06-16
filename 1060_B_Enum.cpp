#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int length[100010];

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &length[i]);
	sort(length + 1, length + i + 1, cmp);
	int Enum = 0;
	for (i = 1; i <= n; i++) {
		if (length[i] > i) Enum++;
		else break;
	}
	printf("%d\n", Enum);
	return 0;
}