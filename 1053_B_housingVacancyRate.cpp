#include<cstdio>
using namespace std;

int main() {
	int n, D, maybe = 0, vacancy = 0;
	float e;
	scanf("%d %f %d", &n, &e, &D);
	int i = 0, day, below, j;
	float ele;
	for (i = 0; i < n; i++) {
		day = 0;
		below = 0;
		scanf("%d", &day);
		for (j = 0; j < day; j++) {
			scanf("%f", &ele);
			if (ele < e) below++;
		}
		if (below > day / 2 && day <= D) maybe++;
		if (below > day / 2 && day > D) vacancy++;
	}
	float maybeRate = 100.0 * maybe / n, vacancyRate = 100.0 * vacancy / n;
	printf("%.1f%% %.1f%%\n", maybeRate, vacancyRate);
	return 0;
}