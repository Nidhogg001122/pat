#include<cstdio>
#include<algorithm>
using namespace std;

//���ͣ���������ָint����
//���ͣ���������ָint����
//���ͣ���������ָint����

//���Լ��
long gcd(long a, long b) {
	return !b ? a : gcd(b, a % b);
}

//�����ı�ʾ��ͨ������ṹ����ʹ������洢
struct fraction {
	long up;
	long down;
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
		long d = gcd(abs(result.up), abs(result.down));
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
	F = reduction(F);
	if (F.up > 0) {
		if (F.up > F.down) {
			printf("%ld", F.up / F.down);
			if (F.up % F.down != 0) printf(" %ld/%ld", F.up % F.down, F.down);
		}
		else if (F.up == F.down) printf("1");
		else printf("%ld/%ld", F.up, F.down);
	}
	else if (F.up < 0) {
		if (abs(F.up) > F.down) {
			printf("(%ld", F.up / F.down);
			if (abs(F.up) % F.down != 0) printf(" %ld/%ld)", abs(F.up) % F.down, F.down);
			else printf(")");
		}
		else if (F.up == -F.down) printf("(-1)");
		else printf("(%ld/%ld)", F.up, F.down);
	}
	else printf("0");
	
}

int main() {
	fraction a, b;
	scanf("%ld/%ld %ld/%ld", &a.up, &a.down, &b.up, &b.down);
	show(a);
	printf(" + ");
	show(b);
	printf(" = ");
	show(add(a, b));
	printf("\n");
	show(a);
	printf(" - ");
	show(b);
	printf(" = ");
	show(minu(a, b));
	printf("\n");
	show(a);
	printf(" * ");
	show(b);
	printf(" = ");
	show(multi(a, b));
	printf("\n");
	show(a);
	printf(" / ");
	show(b);
	printf(" = ");
	if (b.up == 0) printf("Inf");
	else show(divide(a, b));
	printf("\n");
	return 0;
}