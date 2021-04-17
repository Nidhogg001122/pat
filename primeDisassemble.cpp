#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 100001;
/*
* �����ӷֽ⼴��һ���������ֽ��һ�����������˻�����ʽ
* ���磺6=2x3,8=2x2x2
* ����һ��������n���ԣ���֪������������һ����sqrt(n)����
* �������ӷֽ��У�������1���䱾�������������ӣ�������
* �ض�ȫ��С�ڵ���sqrt(n)�������һ������sqrt(n)
*/

//���������ӽṹ�洢�������Ϊ2x3x5x7x11x13x17x23x29����int��Χ����ʮ��Ҳ������
struct factor {
	int fac, num;	//facΪ�����ӣ�numΪ���ĸ���
}befInt[maxn];

int prime[maxn], primeNum;
/*
* 1.��2~sqrt(n)�б����������ж��Ƿ���n������
* ��p�ǣ����¼��������������ٲ���n/p����n����Ϊ���ӣ���������
* ��p���ǣ�������һ������
* 2.�����������̣���n����Ϊ1��˵�����ڴ���sqrt(n)�����ӣ�����Ϊ�����һ�����ڣ�����ʱn����
*/
int findFactor(long n) {
	int result = 0;
	int sqr = (int)sqrt(n * 1.0);
	for (int i = 0; i < primeNum && prime[i] <= sqr; i++) {
		if (n % prime[i] == 0) {
			befInt[result].fac = prime[i];
			befInt[result].num = 0;
			while (n % prime[i] == 0) {
				befInt[result].num++;
				n /= prime[i];
			}
			result++;
		}
		if (n == 1) break;
	}
	if (n != 1) {
		befInt[result].fac = n;
		befInt[result].num = 1;
		result++;
	}
	return result;
}

bool isPrime(int n) {
	if (n == 1) return false;
	int sqr = (int)sqrt(n * 1.0);
	for (int i = 2; i < sqr; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void findPrime() {
	primeNum = 0;
	for (int i = 1; i < maxn; i++) {
		if (isPrime(i)) {
			prime[primeNum++] = i;
		}
	}
}

int main() {
	findPrime();
	int i, num;	//�����Ӹ���
	long n;
	scanf("%ld", &n);
	if (n == 1) printf("1=1\n");	//����
	else {
		num = findFactor(n);
		printf("%d=", n);
		for (i = 0; i < num - 1; i++) {
			if (befInt[i].num == 1) printf("%d*", befInt[i].fac);
			else printf("%d^%d*", befInt[i].fac, befInt[i].num);
		}
		if (befInt[i].num == 1) printf("%d\n", befInt[i].fac);
		else printf("%d^%d\n", befInt[i].fac, befInt[i].num);
	}
}