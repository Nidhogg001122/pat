#include<cstdio>
#include<algorithm>
using namespace std;

//���Լ��
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

//�����ı�ʾ��ͨ������ṹ����ʹ������洢
struct fraction {
	int up;
	int down;
};

/*
* �Է�������Լ��
* 1.ʹ��ĸΪ�Ǹ���������ĸΪ����ʱ��תΪ����������Ϊ����
* 2.������Ϊ0��ʹ����Ϊ0����ĸΪ1
* 3.���ӷ�ĸ��򣬼�û��1����Ĺ�Լ��
* 
* ��������Լ�����������ԶԷ������л���
* 1.����ĸΪ������ʹ���ӷ�ĸ��ȡ�෴��
* 2.������Ϊ0��ʹ��ĸΪ1
* 3.���ӷ�ĸͬʱ�������Ǿ���ֵ�����Լ��
*/

fraction reduction(fraction result) {
	if (result.down < 0) {
		result.down = -result.down;
		result.up = -result.up;
	}
	if (result.up == 0) result.down = 1;
	else {
		int d = gcd(abs(result.up), abs(result.down));
		result.down /= d;
		result.up /= d;
	}
	return result;
}

//����F1��F2��������

//�����ӷ�
fraction add(fraction F1, fraction F2) {
	fraction result;
	result.down = F1.down * F2.down;
	result.up = F1.up * F2.down + F2.up * F1.down;
	return reduction(result);
}

//��������
fraction minu(fraction F1, fraction F2) {
	fraction result;
	result.down = F1.down * F2.down;
	result.up = F1.up * F2.down - F2.up * F1.down;
	return reduction(result);
}

//�����˷�
fraction multi(fraction F1, fraction F2) {
	fraction result;
	result.down = F1.down * F2.down;
	result.up = F1.up * F2.up;
	return reduction(result);
}

//��������
fraction divide(fraction F1, fraction F2) {
	fraction result;
	result.down = F1.down * F2.up;
	result.up = F1.up * F2.down;
	return reduction(result);
}

/*
* ������չʾ��
* ����
* 1.��������ĸΪ1���������
* 2.���Ӿ���ֵ���ڷ�ĸ�����������������up/down,����abs(up)%down
* 3.����������
*/

void show(fraction F) {
	F=reduction(F);
	if (F.down == 1) printf("%d", F.up);
	else if (abs(F.up) > F.down) printf("%d %d/%d", F.up / F.down, abs(F.up) % F.down, F.down);
	else printf("%d/%d", F.up, F.down);
}

int main() {
	fraction a, b;
	scanf("%d%d%d%d", &a.up, &a.down, &b.up, &b.down);
	if (a.down == 0 || b.down == 0) {
		printf("Error");
		exit(-1);
	}
	show(a);
	printf("\n");
	show(b);
	printf("\n");
	printf("a+b=");
	show(add(a, b));
	printf("\n");
	printf("a-b=");
	show(minu(a, b));
	printf("\n");
	printf("a*b=");
	show(multi(a, b));
	printf("\n");
	printf("a/b=");
	show(divide(a, b));
}