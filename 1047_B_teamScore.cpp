#include<cstdio>
#include<algorithm>
using namespace std;

struct data {
	int id;
	int score;
}teams[10010];

bool cmp(struct data a, struct data b) {
	return a.score > b.score;
}

int main() {
	int n, i, teamid, personid, score;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d-%d %d", &teamid, &personid, &score);
		teams[teamid].id = teamid;
		teams[teamid].score += score;
	}
	sort(teams, teams + 10010, cmp);
	printf("%d %d\n", teams[0].id, teams[0].score);
	return 0;
}