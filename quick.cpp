#include<cstdio>

//求（a的b次方）%m，常规下可使用循环完成,使用 long long防止溢出
long long normalPow(long long a, long long b,long long m) {
	long long result = 1;
	for (int i = 1; i <= b; i++) {
		result = result * a % m;	//result先乘a再求模
	}
	return result;
}

/*对于循环做法，其时间复杂度为O(b)，在b较小情况下可行，但当b趋近一个
* 极大的数，如十的十几次方时，处理将变得困难；
* 快速幂：
* 1.若b为偶数，a^b=a^(b/2)*a^(b/2);
* 2.若b为奇数，a^b=a*a^(b-1)；
* 综上，若b为偶数，将其二分，若b为奇数，经2转化后变回1；
* 例如2^5
* 2^5=2*2^4；
* 2^4=2^2*2^2；
* 2^2=2^1*2^1;
* 2^1=2*2^0;
* 2^0=1,	return
*/

//由快速幂的形式可以看出，较为适合递归实现
long long quickPow(long long a, long long b, long long m) {
	if (b == 0) return 1;		//b为0，a∧b=0,结束
	if (b&1) return a * quickPow(a, b - 1, m)%m;		//判断奇数,b二进制与1进行按位与，最后一位为1是奇数，与运算得1
	else {
		long long temp = quickPow(a, b / 2, m);		//新建中间变量，不用quickPow(a, b / 2, m)*quickPow(a, b / 2, m)，减少一半递归过程
		return temp * temp % m;
	}
}

//递归实现的快速幂时间复杂度O(logb),提升了计算上限；

/*
* 迭代实现的快速幂应当与递归实现的效果差不多；
* 对于b,可将其转化为二进制数，例如b=9=1001;
* a^b,可以表示成a^(2^k)……a^8,a^4,a^2,a^1中若干项乘积，每一项都是后一项的平方倍，选取哪些项由b二进制数决定；
* 开始result为1；
* 1.将b与1按位与即可直到二进制最后一位是否为1；
* 2.若为1，则result*a，就是上述a^b由若干项乘积组成;
* 3.将a平方，因a^(2^k)……a^8,a^4,a^2,a^1中，每一项都是后一项的平方倍
* 4.b>0则重复1~4；
* 
* 例如a^9=a^8*a^1
* 
* b		b&1		a		result
*				a		  1
* 1001	 1		a^2		  a
* 100	 0		a^4		  a
* 10	 0		a^8		  a
* 1		 1		a^16	  a*a^8
*/

long long quick_Pow(long long a, long long b, long long m) {
	long long result = 1;
	while (b > 0) {
		if (b & 1) {
			result = result * a % m;
		}
		a = a * a % m; 
		b >>= 1;
	}
	return result;
}

int main() {
	long long a , b , m ;
	scanf("%lld%lld%lld", &a, &b, &m);
	printf("\n%lld\n", quick_Pow(a, b, m));
}