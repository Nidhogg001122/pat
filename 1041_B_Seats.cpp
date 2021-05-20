#include<cstdio>
#include<algorithm>
using namespace std;

struct data {
	char num[32];
	int pre;
	int test;
}student[1010];

bool cmp(struct data a, struct data b) {
	return a.pre < b.pre;
}

int main() {
	int total, missnum, miss[1010];
	scanf("%d", &total);
	int i;
	for (i = 0; i < total; i++) {
		scanf("%s %d %d", &student[i].num, &student[i].pre, &student[i].test);
	}
	sort(student, student + total, cmp);
	scanf("%d", &missnum);
	for (i = 0; i < missnum; i++) scanf("%d", &miss[i]);
	for (i = 0; i < missnum; i++) {
		printf("%s %d\n", student[miss[i]-1].num, student[miss[i]-1].test);
	}
	return 0;
}