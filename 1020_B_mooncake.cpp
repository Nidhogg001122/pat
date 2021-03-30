#include<cstdio>
#include<algorithm>
using namespace std;

struct data {
	double num;		//���
	double total;	//���ۼ�
	double price;	//����
}mooncake[1600];		//����ṹ����洢

bool cmp(struct data a, struct data b) {
	return a.price > b.price;		//�Ե��۴Ӹߵ�������
}

int main() {
	double result=0, need;
	int kind;
	scanf("%d%lf", &kind, &need);
	int i = 0;
	for (i = 0; i < kind; i++) {
		scanf("%lf", &mooncake[i].num);
	}
	for (i = 0; i < kind; i++) {
		scanf("%lf", &mooncake[i].total);
	}
	for (i = 0; i < kind; i++) {
		mooncake[i].price = mooncake[i].total / mooncake[i].num;
	}
	//������Ϣ�洢
	sort(mooncake, mooncake + kind, cmp);	//����

	for (i = 0; i < kind; i++) {
		if (need <= mooncake[i].num) {
			result += need * mooncake[i].price;		//�������С�ڴ����±���Ŀ,���������������˳�
			break;
		}
		else {
			result += mooncake[i].total;		//���������ڴ����±���Ŀ,�������д��±�
			need -= mooncake[i].num;			//�������
		}
	}

	printf("%.2lf", result);
}