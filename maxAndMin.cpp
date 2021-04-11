#include<cstdio>
using namespace std;

/*
* 最大公约数
* 两个正整数a和b的最大公约数是两者所有公约数中最大的一个，即gcd(a,b)
* 计算最大公约数一般使用欧几里得算法，即辗转相除法
* 核心:gcd(a,b)=gcd(b,a%b)
* 证明：设a=kb+r
* r=a-kb
* 若d是a和b的一个公约数,则d也为r的一个约数
* 而r=a%b,所以d也为a%b的一个约数
* 由d的任意性，a和b的所有公约数也是b和a%b的公约数
* 由a=kb+r，同理可证b和a%b的所有公约数是a和b的公约数
* 所以a和b的所有公约数等于a和a%b的所有公约数
* 故其中最大的也相同
*/

/*
* 解决核心问题后，接下来便是递归过程的边界
* gcd(a,b)=gcd(b,a%b)
* 此定理实现：若a<b,则将两者交换，否则，缩小范围
* 引入0和a的最大公约数为a,不是0，故边界条件gcd(a,0)=a;
* 递归结束条件b=0
*/
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
	//或者 return !b?a:a%b	但我觉得这除了炫技毫无意义
}

/*
* 解决最小公约数后，最小公倍数便迎刃而解
* lcm(a,b)=ab/gcd(a,b)
* 在ab的时候可能溢出，故尝试(a/gcd(a,b))b
*/

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

int main() {
	printf("%d\n", gcd(49, 14));
	printf("%d", lcm(24, 16));
}