#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

const int maxn = 100001;
int prime[maxn];
int judge[maxn];
int num = 0;

/*
* ����
* ����1���������ܱ������κ�����������
* �ж�һ�����Ƿ������������Դ�2~n-1����ѭ���������Ƿ��ܱ�����
* �˷������Ӷ�ΪO(n),�������ǿ��Խ��ܵ�
* �������ж�һ�����Ƿ�����������������һ����Ӧ���������临�Ӷ�
* ����k��2~n-1�У�Ϊn��һ��Լ������n%k=0
* ��Ȼn/kҲ��2~n-1�У�Ϊ��һ��Լ��
* sqrt(n)Ϊ����n;
* k��n/k��Ȼ��һ������sqrt(n)��һ��С��sqrt(n)
* ����ֻ��ѭ����sqrt(n)��ʱ�临�Ӷ�ΪO(sqrt(n))
*/

bool isPrime(int n) {
	if (n <= 1) return false;	//1�Ȳ�������Ҳ���Ǻ���
	int sqr = (int)sqrt(n * 1.0);	//sqrt�Ĳ�����Ҫ��һ��������
	for (int i = 2; i <= sqr; i++) {
		if (!(n % i)) return false;
	}
	return true;
}

/*
* �����������Ļ�ȡ����1~n����������
* ��1~n����ö�٣�ʱ�临�Ӷ�ΪO(n),��ö�ٵ��������жϣ�ʱ�临�Ӷ�ΪO(sqrt(n))
* �ܵ�ʱ�临�Ӷ�ΪO(n*sqrt(n))
*/


void primeTable(int n) {
	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) prime[num++] = i;
	}
}

/*
* ��n����10^5�ڣ������㷨ʱ����Խ��ܵģ����ڸ��������
* ʹ��ɸ��������һЩ������ɸ�����нϼ򵥵�����
* �����˼�����ҵ�һ������������ȥ�������б���
* �����ҵ�2���򽫱���4��6��8����ȫ����ȥ
* ��ȥ�Ĺ�������һ�������ж�
* ���㷨ʱ�临�Ӷ�O(n*loglogn)
*/

void primeTableLarge(int n) {
	int i = 0, j = 0;
	for (i = 2; i <= n; i++) {
		if (!judge[i - 1]) {
			prime[num++] = i;
			for (j = i + i; j <= n; j+=i) {	//��ȥ���б���
				judge[j - 1] = 1;
			}
		}
	}
}

/*
* ��ʱ������ɸ�Ѿ�������ɼ������������ˣ��������ٴ����󣬻�����ʹ��ŷ��ɸ��
* ŷ��ɸ���Ļ����ǰ���ɸ��Ҳ����˵���ǰ���ɸ��һ���Ż�
* �ڰ���ɸ�У�ͬһ�����������ܱ���ͬ����������ɸѡ��
* ����24�ᱻ2ɸѡ���ֱ�3ɸѡ������ϣ����ֻ��һ������ɸѡ�������ŷ��ɸ����ԭ��
* ��ʱ�临�Ӷ�ΪO(n)
*/

void primeTableBetter(int n) {
	int i = 0, j = 0;
	for (i = 2; i <= n; i++) {
		if (!judge[i-1]) {
			prime[num++] = i;
		}
		for (j = 0; j < num; j++) {
			if (i * prime[j] > n) break;	//Խ�����
			judge[i * prime[j]-1] = true;
			if ((i % prime[j]) == 0) break;	//ֻ��һ����������
		}
	}
}

int main() {
	printf("%d\n", isPrime(5));
	primeTable(100);
	for (int i = 0; i < num; i++) {
		printf("%d ", prime[i]);
	}
	num = 0;
	printf("\n");
	
	primeTableLarge(100);
	for (int i = 0; i < num; i++) {
		printf("%d ", prime[i]);
	}
	printf("\n");
	
	/*
	primeTableBetter(100);
	for (int i = 0; i < num; i++) {
		printf("%d ", prime[i]);
	}
	*/
}