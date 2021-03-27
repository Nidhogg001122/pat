#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct data {
	char id[20];	//ѧ��ѧ��
	int local = 0;	//������
	int score = 0;	//����
	int total_rank = 0, local_rank = 0;	//�������Ϳ�������
}student[1000];

bool cmp(struct data a,struct data b) {
	if (a.score != b.score) return a.score > b.score;	//��ͬ�ְ��ɼ��Ӵ�С
	else return strcmp(a.id, b.id)<0;		//ͬ�ְ�ѧ�Ŵ�С����
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
		}		//��ȡһ������ѧ����Ϣ,numΪѧ������

		sort(student+num - m, student+num, cmp);		//�Դ˿���ѧ������

		student[num - m].local_rank = 1;		//�˿�����һ��
		int r = 2;
		for (int j = num - m+1; j < num; j++) {
			if (student[j].score != student[j - 1].score) student[j].local_rank = r; //��ͬ��������
			else student[j].local_rank = student[j-1].local_rank;		//��ͬ����ͬ����
			r++;
		}		//���ź���Ĵ˿���ѧ����������
	}

	sort(student, student + num,cmp);		//������ѧ������

	student[0].total_rank = 1;		//�����һ��
	int r = 2;
	for (int i = 1; i < num; i++) {
		if (student[i].score != student[i - 1].score) student[i].total_rank = r; //��ͬ��������
		else student[i].total_rank = student[i-1].total_rank;		//��ͬ����ͬ����
		r++;
	}

	//�������
	printf("%d", num);
	for (int i = 0; i < num; i++) {
		printf("%s %d %d %d\n", student[i].id, student[i].total_rank, student[i].local, student[i].local_rank);
	}
}