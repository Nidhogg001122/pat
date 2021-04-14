#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

const int maxn = 100001;
int prime[maxn];
int judge[maxn];
int num = 0;

/*
* 素数
* 除了1和它本身不能被其他任何数整除的数
* 判断一个数是否是素数，可以从2~n-1进行循环，查找是否能被整除
* 此方法复杂度为O(n),看起来是可以接受的
* 但往往判断一个数是否是素数仅仅是其中一步，应尽量降低其复杂度
* 假设k在2~n-1中，为n的一个约数，即n%k=0
* 显然n/k也在2~n-1中，为另一个约数
* sqrt(n)为根号n;
* k与n/k必然是一个大于sqrt(n)，一个小与sqrt(n)
* 所以只需循环至sqrt(n)，时间复杂度为O(sqrt(n))
*/

bool isPrime(int n) {
	if (n <= 1) return false;	//1既不是素数也不是合数
	int sqr = (int)sqrt(n * 1.0);	//sqrt的参数需要是一个浮点数
	for (int i = 2; i <= sqr; i++) {
		if (!(n % i)) return false;
	}
	return true;
}

/*
* 其次是素数表的获取，求1~n中所有素数
* 对1~n进行枚举，时间复杂度为O(n),对枚举的数进行判断，时间复杂度为O(sqrt(n))
* 总的时间复杂度为O(n*sqrt(n))
*/


void primeTable(int n) {
	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) prime[num++] = i;
	}
}

/*
* 在n处于10^5内，上述算法时间可以接受的，对于更大的数据
* 使用筛法会更简便一些，埃氏筛是其中较简单的做法
* 其核心思想是找到一个素数，而后划去它的所有倍数
* 例如找到2，则将表中4，6，8……全部划去
* 划去的过程由另一个数组判断
* 此算法时间复杂度O(n*loglogn)
*/

void primeTableLarge(int n) {
	int i = 0, j = 0;
	for (i = 2; i <= n; i++) {
		if (!judge[i - 1]) {
			prime[num++] = i;
			for (j = i + i; j <= n; j+=i) {	//划去所有倍数
				judge[j - 1] = 1;
			}
		}
	}
}

/*
* 此时，埃氏筛已经可以完成几乎所有问题了，若数据再次扩大，还可以使用欧拉筛法
* 欧拉筛法的基础是埃氏筛，也可以说它是埃氏筛的一个优化
* 在埃氏筛中，同一个合数，可能被不同的素数因子筛选。
* 例如24会被2筛选，又被3筛选，我们希望它只被一个因子筛选，这就是欧拉筛法的原理
* 其时间复杂度为O(n)
*/

void primeTableBetter(int n) {
	int i = 0, j = 0;
	for (i = 2; i <= n; i++) {
		if (!judge[i-1]) {
			prime[num++] = i;
		}
		for (j = 0; j < num; j++) {
			if (i * prime[j] > n) break;	//越界结束
			judge[i * prime[j]-1] = true;
			if ((i % prime[j]) == 0) break;	//只到一个素数因子
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