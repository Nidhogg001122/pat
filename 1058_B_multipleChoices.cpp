#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct{
	int score;
	int choice_num;
	int right_num;
	char ans[8];
}question[128];

typedef struct data {
	int stu_num;
	char stu_ans[8];
}Stu_ans;

struct{
	int stu_score;
	Stu_ans ans[128];
}student[1024];

struct res{
	int id;
	int count;
}result[1024];

bool cmp(struct res a, struct res b) {
	if (a.count > b.count) return true;
	else if (a.count < b.count) return false;
	else return a.id < b.id;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j, k;
	char c;
	for (i = 0; i < m; i++) {
		scanf("%d %d %d ", &question[i].score, &question[i].choice_num, &question[i].right_num);
		j = 0;
		c = getchar();
		while (c != '\n') {
			question[i].ans[j++] = c;
			c = getchar();
		}
	}
	for (i = 0; i < n; i++) {
		student[i].stu_score = 0;
		k = 0;
		c = getchar();
		while (c != '\n') {
			scanf("%d ", &student[i].ans[k].stu_num);
			j = 0;
			c = getchar();
			while (c != ')') {
				student[i].ans[k].stu_ans[j++] = c;
				c = getchar();
			}
			c = getchar();
			if (c == '\n') break;
			c = getchar();
			k++;
		}
	}
	for (i = 0; i < m; i++) {
		result[i].id = i + 1;
		result[i].count = 0;
	}
	int judge;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (student[i].ans[j].stu_num != question[j].right_num) {
				result[j].count++;
				continue;
			}
			judge = strcmp(student[i].ans[j].stu_ans, question[j].ans);
			if (!judge) student[i].stu_score+=question[j].score;
			else result[j].count++;
		}
	}
	for (i = 0; i < n; i++) printf("%d\n", student[i].stu_score);
	sort(result, result + m, cmp);
	if (result[0].count == 0) printf("Too simple\n");
	else {
		printf("%d %d", result[0].count, result[0].id);
		for (i = 0; i < m; i++) {
			if (result[i].count == result[0].count) printf(" %d", result[i].id);
			else break;
		}
		printf("\n");
	}
	return 0;
}