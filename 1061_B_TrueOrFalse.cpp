#include<cstdio>
using namespace std;

struct data {
	int score;
	int judge;
}question[128];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < m; i++) scanf("%d", &question[i].score);
	for (i = 0; i < m; i++) scanf("%d", &question[i].judge);
	int score, ans;
	for (i = 0; i < n; i++) {
		score = 0;
		for (j = 0; j < m; j++) {
			scanf("%d", &ans);
			if (ans == question[j].judge) score += question[j].score;
		}
		printf("%d\n", score);
	}
	return 0;
}