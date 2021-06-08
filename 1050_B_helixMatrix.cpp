#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int num[10010], result[10010][10010];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int all, i, j;
	scanf("%d", &all);
	for (i = 0; i < all; i++) scanf("%d", &num[i]);
	sort(num, num + all, cmp);
	int m, n;
	n = sqrt(all);
	while (all % n != 0) n--;
	m = all / n;
	int count = (n % 2 == 0 ? n / 2 : n / 2 + 1);
	int urow = 0, brow = m - 1, lline = 0, rline = n - 1;
	for (i=0; count>0; count--) {
		for (j = lline; j <= rline && i < all; j++, i++) result[urow][j] = num[i];
		urow++;
		for (j = urow; j <= brow && i < all; j++, i++) result[j][rline] = num[i];
		rline--;
		for (j = rline; j >= lline && i < all; j--, i++) result[brow][j] = num[i];
		brow--;
		for (j = brow; j >= urow && i < all; j--, i++) result[j][lline] = num[i];
		lline++;
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d", result[i][j]);
			if (j == n - 1) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}