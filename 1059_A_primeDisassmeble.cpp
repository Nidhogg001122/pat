#include<cstdio>
#include<cmath>
using namespace std;

const int maxn = 100001;
/*
* 质因子分解即将一个正整数分解成一个或多个质数乘积的形式
* 例如：6=2x3,8=2x2x2
* 对于一个正整数n而言，已知它的两个因子一定在sqrt(n)两边
* 在质因子分解中，若存在1和其本身外其他质因子，则它们
* 必定全都小于等于sqrt(n)，或仅有一个大于sqrt(n)
*/

//定义质因子结构存储结果，因为2x3x5x7x11x13x17x23x29大于int范围，开十个也可以了
struct factor {
	int fac, num;	//fac为质因子，num为它的个数
}befInt[maxn];

int prime[maxn], primeNum;
/*
* 1.在2~sqrt(n)中遍历质数，判断是否是n的因子
* 若p是，则记录并增加其个数，再不断n/p，若n依旧为因子，数量增加
* 若p不是，继续下一个质数
* 2.结束上述过程，若n还不为1，说明存在大于sqrt(n)的因子，又因为最多有一个大于，即此时n本身
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
	int i, num;	//质因子个数
	long n;
	scanf("%ld", &n);
	if (n == 1) printf("1=1\n");	//特例
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