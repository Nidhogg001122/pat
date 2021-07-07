#include<cstdio>
using namespace std;

int main() {
	int T, K;
	scanf("%d %d", &T, &K);
	int n1, b, t, n2;
	while (T > 0 && K > 0) {
		scanf("%d %d %d %d", &n1, &b, &t, &n2);
		if (t > T) {
			printf("Not enough tokens.  Total = %d.\n", T);
			K--;
		}
		else {
			if ((n1 > n2 && b == 0) || (n1 < n2 && b == 1)) {
				T += t;
				printf("Win %d!  Total = %d.\n", t, T);
				K--;
			}
			else {
				T -= t;
				printf("Lose %d.  Total = %d.\n", t, T);
				K--;
			}
			if (T <= 0) printf("Game Over.\n");
		}
	}
	return 0;
}