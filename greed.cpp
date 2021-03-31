#include<cstdio>
#include<algorithm>
using namespace std;

/*
* ����̰�ģ�
* ���翪���䲻�ཻ���⣺���ڸ����Ķ�������䣬�ҳ�����м������ཻ����1��3������2��4������3��5��
* ��������1��3������3��5��
* 
* �򵥿��ǣ������������а�����ϵ��Ӧ��ѡ���С�����䣬����������ռ�ѡȡ�������䣻
* ���������䰴��˵�Ӵ�С���У���˵���ͬ���Ҷ˵�С�������磺
*			L1_________R1
*		L2_______R2
*	L3______R3
*	L4_________L4
* ......
* ���ڵ�һ��������R2�Ҷ˲���ȥ������ص����������ѡ1������ѭ��Ѱ��RС�ڵ���L1�����䣬
* ����Ϊ�����ͬ�Ҷ˴�С���󣬱�Ȼ����˳��ѡ���������Ľ�С������
* 
* ��Ȼ��Ҳ�ɽ���˵��С��������
*/

struct data {
	int left,right;		//��������ṹ���������Ҷ˵�
}space[128];

bool cmp(struct data a, struct data b) {
	if (a.left == b.left) return a.right<b.right;
	else return a.left>b.left;
}
int main() {
	int n = 0,num=0;
	scanf("%d", &n);
	int result[128] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &space[i].left, &space[i].right);
	}
	//������������

	sort(space, space + n, cmp);
	result[0] = 1;
	num = 1;
	int Left = space[0].left;	//ȡ��һ������

	for (int i = 1; i < n; i++) {
		if (space[i].right <= Left) {
			Left = space[i].left;
			result[i] = 1;
			num++;
		}
	}

	printf("\n%d\n", num);
	for (int i = 0; i < n; i++) {
		if (result[i]) printf("(%d,%d)\n", space[i].left, space[i].right);
	}
}