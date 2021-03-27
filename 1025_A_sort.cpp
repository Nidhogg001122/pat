#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct data {
	char id[20];	//学生学号
	int local = 0;	//考场号
	int score = 0;	//分数
	int total_rank = 0, local_rank = 0;	//总排名和考场排名
}student[1000];

bool cmp(struct data a,struct data b) {
	if (a.score != b.score) return a.score > b.score;	//不同分按成绩从大到小
	else return strcmp(a.id, b.id)<0;		//同分按学号从小到大
}

int main() {
	int n = 0,num = 0,local=1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++,local++) {
		int m = 0;
		scanf("%d", &m);
		for (int k=0,j = num; k < m;k++, j++,num++) {
			scanf("%s %d", &student[j].id,&student[j].score);
			student[j].local = i;
		}		//读取一个考场学生信息,num为学生总数

		sort(student+num - m, student+num, cmp);		//对此考场学生排序

		student[num - m].local_rank = 1;		//此考场第一名
		int r = 2;
		for (int j = num - m+1; j < num; j++) {
			if (student[j].score != student[j - 1].score) student[j].local_rank = r; //不同分数排名
			else student[j].local_rank = student[j-1].local_rank;		//相同分数同排名
			r++;
		}		//对排好序的此考场学生进行排名
	}

	sort(student, student + num,cmp);		//对所有学生排名

	student[0].total_rank = 1;		//处理第一名
	int r = 2;
	for (int i = 1; i < num; i++) {
		if (student[i].score != student[i - 1].score) student[i].total_rank = r; //不同分数排名
		else student[i].total_rank = student[i-1].total_rank;		//相同分数同排名
		r++;
	}

	//输出数据
	printf("%d", num);
	for (int i = 0; i < num; i++) {
		printf("%s %d %d %d\n", student[i].id, student[i].total_rank, student[i].local, student[i].local_rank);
	}
}